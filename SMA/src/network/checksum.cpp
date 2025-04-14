#include "checksum.h"

uint32_t CheckSum::CRC32(const std::string& data)
{
	return calculateCrc32(data);
}
