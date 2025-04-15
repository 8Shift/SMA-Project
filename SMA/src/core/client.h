#pragma once

#include <cstdint>
#include <string>

#include "profile.h"

struct PhoneNumber;
struct Bio;
struct Mail;
struct ToxID;

class Client
{
private:
	std::string id;
	std::string name;
	PhoneNumber phoneNumber;
	Bio bio;
	Mail email;
	ToxID tid;
public:
	Client() = default;
	Client(const Client& other) = default;
	Client(Client&& rvalue) = delete;

	~Client() = default;

public:
	void genID();

	void setName(std::string newName);
	void setPhoneNumber(PhoneNumber &num);
	void setToxID(ToxID &id);
	void setMail(Mail &ml);
	void setBio(Bio &description);

	std::string getName() const;
	std::string getId() const;
	Mail getMail();
	PhoneNumber getNumber() const;
	Bio getBio() const;
	ToxID getToxID() const;
};