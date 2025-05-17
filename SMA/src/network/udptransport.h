#include "transportprotocol.h"

class UdpTransport : public ITransport
{
public:
	UdpTransport() = default;
	UdpTransport(const UdpTransport& other) = default;
	UdpTransport(UdpTransport&& rvalue) = delete;

	virtual ~UdpTransport() = default;
public:
	int connection(const std::string& hostname, uint32_t port) override;
	int listening() override;
	void generatePublicKey() override;
	int sendMessage(SMAProtocol req) override;
	SMAProtocol recieveMessage() override;
	void disconnect() override;
};