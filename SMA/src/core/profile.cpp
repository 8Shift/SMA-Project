#include <string>

#include "profile.h"
#include "uuid_v4.h"

std::string PhoneNumber::toStdString()
{
    return std::to_string(countryCode + number);
}

std::string Mail::toStdString()
{
    std::string result = name + std::to_string(mailChar) + host;
    return result;
}

Mail& Mail::operator=(const Mail& other)
{
    host = other.host;
    name = other.name;
    return *this;
}

ToxID::ToxID(const std::string& hex)
{
    if (hex.length() != 76)
    {
        throw std::invalid_argument("Invalid ToxID length");
    }
    id = hex;
}

void ClientProfile::genID()
{
	UUIDv4::UUIDGenerator<std::mt19937_64> uuidGenerator;
	UUIDv4::UUID uuid = uuidGenerator.getUUID();

	id = uuid.bytes();
}

void ClientProfile::setName(std::string newName)
{
	name = newName;
}

void ClientProfile::setPhoneNumber(PhoneNumber& num)
{
	phoneNumber = num;
}

void ClientProfile::setToxID(ToxID& id)
{
	tid = id;
}

void ClientProfile::setMail(Mail& ml)
{
	email = ml;
}

void ClientProfile::setBio(Bio& description)
{
	bio = description;
}

std::string ClientProfile::getName() const
{
	return name;
}

std::string ClientProfile::getId() const
{
	return id;
}

Mail ClientProfile::getMail()
{
	return email;
}

PhoneNumber ClientProfile::getNumber() const
{
	return phoneNumber;
}

Bio ClientProfile::getBio() const
{
	return bio;
}

ToxID ClientProfile::getToxID() const
{
	return tid;
}