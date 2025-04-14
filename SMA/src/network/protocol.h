#pragma once

#include <cstdint>

enum class SMAProtocolType;

struct SMAProtocolHeader;
struct SMAProtocol; // header + binary data

namespace Protocol
{
	void serialize(SMAProtocol msg, std::vector <uint8_t>& to);
	void deserialize(std::vector <uint8_t> buff, SMAProtocol& proto);
}