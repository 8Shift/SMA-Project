#include <cstdint>
#include <sstream>
#include <stdexcept>

#include "serverlist.h"

std::string IPV4::toStdString() const
{
	std::string sumResult;
	for (int i = 0; i < 4; ++i)
	{
		sumResult += octets[i];
	}

	return sumResult;
}

void IPV4::fromStdString(const std::string& ipv4)
{
    std::istringstream iss(ipv4);
    std::string octetStr;
    std::vector <uint8_t> parsedOctets;

    while (std::getline(iss, octetStr, '.'))
    {
        try
        {
            int octet = std::stoi(octetStr);
            if (octet < 0 || octet > 255)
            {
                throw std::out_of_range("Octet must be between 0 and 255");
            }
            parsedOctets.push_back(static_cast<uint8_t>(octet));
        }
        catch (const std::invalid_argument&)
        {
            throw std::invalid_argument("Invalid ipv4 format (octet is not a number)");
        }
        catch (const std::out_of_range&)
        {
            throw std::out_of_range("Invalid ipv4 format (octet out of range)");
        }
    }

    if (parsedOctets.size() != 4)
    {
        throw std::invalid_argument("Invalid IPv4 format (expected 4 octets)");
    }

    for (size_t i = 0; i < 4; ++i)
    {
        octets[i] = parsedOctets[i];
    }
}

