
#include "app.h"

#include "../network/udptransport.h"
#include "../network/tcptransport.h"

class SMAServer : public IApplication
{
private:
	size_t clientCount;
	std::vector <SOCKET> clients;
public:
	SMAServer();
	SMAServer(const SMAServer& other) = delete;
	SMAServer(SMAServer&& rvalue) = delete;

	virtual ~SMAServer() = default;

	int fExit() override;

	int exec() override;

	void setProtocol(std::string_view type) override;
};