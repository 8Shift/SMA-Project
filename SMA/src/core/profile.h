#pragma once

#include <stdexcept>

struct PhoneNumber
{
    uint32_t countryCode;
    uint32_t number;

    std::string toStdString();
};

struct Bio
{
    std::string text;
};

struct Mail
{
    const char mailChar = '@';
    std::string host;
    std::string name;

    std::string toStdString();

    Mail& operator= (const Mail& other);
};

struct ToxID
{
    std::string id;
    explicit ToxID(const std::string& hex);
};

class ClientProfile
{
private:
	std::string id;
	std::string name;
	PhoneNumber phoneNumber;
	Bio bio;
	Mail email;
	ToxID tid;
public:
	ClientProfile() = default;
	ClientProfile(const ClientProfile& other) = default;
	ClientProfile(ClientProfile&& rvalue) = delete;

	~ClientProfile() = default;

public:
	void genID();

	void setName(std::string newName);
	void setPhoneNumber(PhoneNumber& num);
	void setToxID(ToxID& id);
	void setMail(Mail& ml);
	void setBio(Bio& description);

	std::string getName() const;
	std::string getId() const;
	Mail getMail();
	PhoneNumber getNumber() const;
	Bio getBio() const;
	ToxID getToxID() const;
};