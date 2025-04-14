#pragma once

#include "client.h"

struct PhoneNumber
{
    uint32_t countryCode;
    uint32_t number;
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
};

struct ToxID
{
    std::string id;
    explicit ToxID(const std::string& hex)
    {
        if (hex.length() != 76)
        {
            throw std::invalid_argument("Invalid ToxID length");
        }
        id = hex;
    }
};

struct ClientInfo
{
    PhoneNumber phoneNumber;
    Bio bio;
    Mail email;
    ToxID toxId;
};