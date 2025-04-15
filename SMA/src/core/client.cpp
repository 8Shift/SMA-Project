#include "uuid_v4.h"

#include "client.h"

void Client::genID()
{
	UUIDv4::UUIDGenerator<std::mt19937_64> uuidGenerator;
	UUIDv4::UUID uuid = uuidGenerator.getUUID();

	id = uuid.bytes();
}

void Client::setName(std::string newName)
{
	name = newName;
}

void Client::setPhoneNumber(PhoneNumber &num)
{
	phoneNumber = num;
}

void Client::setToxID(ToxID &id)
{
	tid = id;
}

void Client::setMail(Mail &ml)
{
	email = ml;
}

void Client::setBio(Bio &description)
{
	bio = description;
}

std::string Client::getName() const
{
	return name;
}

std::string Client::getId() const
{
	return id;
}

Mail Client::getMail()
{
	return email;
}

PhoneNumber Client::getNumber() const
{
	return phoneNumber;
}

Bio Client::getBio() const
{
	return bio;
}

ToxID Client::getToxID() const
{
	return tid;
}