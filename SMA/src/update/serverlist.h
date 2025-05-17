#pragma once

#include <string>
#include <fstream>
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
	std::string name;
	ServerNodeStatus status;
	ServerNodeType type;
	IPV4 ipv4;
	uint32_t ping;
};

class ServerList
{
private:
	std::vector <ServerListNode> nodes;
	std::fstream configFile;
public:
	ServerList() = default;
	ServerList(std::string filename);
	ServerList(const ServerList& other) = delete;
	ServerList(ServerList&& rvalue) = delete;

	~ServerList();

public:
	void loadServerList();
	void exportServerList();
	void addServerNode();
	void deleteServerNode();
};