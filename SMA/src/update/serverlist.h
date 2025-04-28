#pragma once

#include <string>
#include <vector>

#include "json.hpp"

struct IPV4
{
	uint8_t octets[4];

	std::string toStdString() const;
	void fromStdString(const std::string& ipv4);
};

enum class ServerNodeStatus
{
	ACTIVE,
	ZOMBIE,
	INACTIVE
};

enum class ServerNodeType
{
	OFFICIAL,
	UNOFFICIAL,
	MODIFIED
};

struct ServerListNode
{
	ServerNodeStatus status;
	ServerNodeType type;
	std::string ipv4;
	uint32_t ping;
};

class ServerList
{
private:
	std::vector <ServerListNode> nodes;
	FILE* configFile;
};