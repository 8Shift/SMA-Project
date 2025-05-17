#include "transportprotocol.h"

class TcpTransport : public ITransport
{
public:
	TcpTransport() = default;
	TcpTransport(const TcpTransport& other) = default;
	TcpTransport(TcpTransport&& rvalue) = delete;

	virtual ~TcpTransport() = default;
public:

	int connection(const std::string& hostname, uint32_t port) override;
	int listening() override;
	void generatePublicKey() override;
	int sendMessage(SMAProtocol req) override;
	SMAProtocol recieveMessage() override;
	void disconnect() override;
};