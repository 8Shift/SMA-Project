#pragma once

#include <iostream>
#include <vector>

#include <WS2tcpip.h>
#include <WinSock2.h>
#include <Windows.h>

#include <botan/rng.h>
#include <botan/auto_rng.h>
#include <botan/pubkey.h>
#include <botan/rsa.h>

#include "protocol.h"

#pragma comment(lib, "ws2_32.lib")

class ITransport
{
protected:
	WSAData wsaData{};
	SOCKET sd{};
	sockaddr_in connectAddrInfo{};
	std::vector <uint8_t> inBuff;
	std::vector <uint8_t> outBuff;
	Botan::AutoSeeded_RNG rng;
	std::unique_ptr <Botan::RSA_PrivateKey> RSAKeys;
	std::unique_ptr <Botan::PK_Encryptor_EME> encryptor;
	std::unique_ptr <Botan::PK_Decryptor_EME> decryptor;
public:
	ITransport() = default;
	ITransport(const ITransport &other) = default;
	ITransport(ITransport&& rvalue) = delete;

	virtual ~ITransport() = default;

	virtual int connection(const std::string& hostname, uint32_t port) = 0;
	virtual int listening() = 0;
	virtual void generatePublicKey() = 0;
	virtual int sendMessage(SMAProtocol req) = 0;
	virtual SMAProtocol recieveMessage() = 0;
	virtual void disconnect() = 0;
};