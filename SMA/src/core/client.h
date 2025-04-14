#pragma once

#include <cstdint>
#include <string>
#include <memory>
#include <stdexcept>

#include "clientinfo.h"

struct PhoneNumber;
struct Bio;
struct Mail;
struct ToxID;
struct ClientInfo;

class Client
{
private:
	uint32_t id{NULL};
	std::string name;
	ClientInfo info;
public:
	Client() = default;
	Client(const Client& other) = default;
	Client(Client&& rvalue) = delete;

	~Client() = default;

public:
	void genID();

	void setName(std::string newName);
	void setPhoneNumber(PhoneNumber num);
	void setToxID(ToxID id);
	void setMail(Mail ml);
	void setBio();

	std::string getClientName() const;
	ClientInfo getClientInfo() const;
	uint64_t getClientId() const;
};