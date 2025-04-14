#include <iostream>

#include <botan/hash.h>

#include "crc32.h"

namespace CheckSum
{
	uint32_t CRC32(const std::string &data);
}