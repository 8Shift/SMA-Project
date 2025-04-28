#pragma once

#include <cstdint>

enum class SMAProtocolType;

enum class SMAProtocolType
{
	TEXT,
	ERR,
	FDATA, // File transfer
	COMMAND
};

struct SMAProtocolHeader
{
	SMAProtocolType type;
	uint32_t payloadSize;
	uint32_t checksum;
};

struct SMAProtocol // header + binary data
{
	SMAProtocolHeader header;
	std::vector <uint8_t> payload;
};

namespace Protocol
{
	void serialize(SMAProtocol msg, std::vector <uint8_t>& to);
	void deserialize(std::vector <uint8_t> buff, SMAProtocol& proto);
}