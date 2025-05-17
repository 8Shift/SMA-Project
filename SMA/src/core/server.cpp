#include "server.h"

SMAServer::SMAServer()
{
	flogger.setLogFileName("log.txt");

	profile->genID();
}

void SMAServer::setProtocol(std::string_view type)
{
	if (type == "udp")
	{
		transport = std::make_unique<UdpTransport>();
	}
	else if (type == "tcp")
	{
		transport = std::make_unique<TcpTransport>();
	}
}
