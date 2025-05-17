#include <iostream>
#include <memory>

#include "network/transportprotocol.h"
#include "network/udptransport.h"

int main(int argc, char *argv[]) 
{
    std::unique_ptr <ITransport> tr = std::make_unique<UdpTransport>();

    tr->generatePublicKey();
    tr->connection("127.0.0.1", 65000);

    SMAProtocol msg = tr->recieveMessage();

    auto x = msg.payload;

    for (const auto& it : x)
    {
        std::cout << it;
    }


    return 0;
}