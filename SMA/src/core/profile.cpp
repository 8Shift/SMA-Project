#include "profile.h"

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
