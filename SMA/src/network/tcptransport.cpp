#include <iostream>

#include <botan/auto_rng.h>
#include <botan/hex.h>
#include <botan/pk_keys.h>
#include <botan/pkcs8.h>
#include <botan/pubkey.h>
#include <botan/rng.h>

#include "tcptransport.h"

int TcpTransport::connection(const std::string& hostname, uint32_t port)
{
    if (hostname.length() < 7) { return -1; } // Minimal ip address len (0.0.0.0)

    if (WSAStartup(MAKEWORD(2, 2), &wsaData))
    {
        throw std::runtime_error("Error starting WinSock");
    }

    sd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sd == INVALID_SOCKET)
    {
        return -1;
    }

    memset(&connectAddrInfo, 0, sizeof(connectAddrInfo));
    inet_pton(AF_INET, hostname.c_str(), &connectAddrInfo.sin_addr.s_addr);
    connectAddrInfo.sin_family = AF_INET;
    connectAddrInfo.sin_port = port;

    if (connect(sd, (sockaddr*)&connectAddrInfo, sizeof(connectAddrInfo)) == SOCKET_ERROR)
    {
        return -1;
    }

    return 0;
}

void TcpTransport::generatePublicKey()
{
    RSAKeys = std::make_unique <Botan::RSA_PrivateKey>(rng, 2048);
}

int TcpTransport::sendMessage(SMAProtocol req)
{
    Botan::secure_vector<uint8_t> plaintext(req.payload.begin(), req.payload.end());
    encryptor = std::make_unique<Botan::PK_Encryptor_EME>(RSAKeys, rng, "OAEP(SHA-256)");
    auto ciphertext = encryptor->encrypt(plaintext, rng);
    req.payload.assign(ciphertext.begin(), ciphertext.end());

    Protocol::serialize(req, outBuff);

    int result = send(sd, reinterpret_cast<const char*>(outBuff.data()), outBuff.size(), 0);
    if (result < 0)
    {
        return -1;
    }

    return 0;
}

[[nodiscard]]
SMAProtocol TcpTransport::recieveMessage()
{
    std::vector<uint8_t> temp(4096);

    int result = recv(sd, reinterpret_cast<char*>(temp.data()), temp.size(), 0);

    if (result == SOCKET_ERROR)
    {
        throw std::runtime_error("Socket error: " + std::to_string(WSAGetLastError()));
    }
    else if (result == 0)
    {
        throw std::runtime_error("Connection closed by peer");
    }

    temp.resize(result);
    inBuff.assign(temp.begin(), temp.end());

    SMAProtocol tor;
    Protocol::deserialize(inBuff, tor);

    decryptor = std::make_unique <Botan::PK_Decryptor_EME>(RSAKeys, rng, "OAEP(SHA-256)");
    auto plaintext = decryptor->decrypt(tor.payload);
    
    tor.payload = std::move(std::vector <uint8_t>(plaintext.begin(), plaintext.end()));

    return tor;
}

void TcpTransport::disconnect()
{
    closesocket(sd);
    WSACleanup();
}
