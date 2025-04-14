#include <vector>
#include <stdexcept>

#include "protocol.h"

enum class SMAProtocolType
{
	TEXT,
	ERROR,
	FDATA, // File transfer
	COMMAND
};

struct SMAProtocolHeader
{
	SMAProtocolType type;
	uint32_t payloadSize;
};

struct SMAProtocol
{
	SMAProtocolHeader header;
	std::vector <uint8_t> payload;
};

namespace Protocol
{
	void serialize(SMAProtocol msg, std::vector <uint8_t>& to)
	{
		size_t msgHeaderSize = sizeof(msg.header);

		to.clear();
		to.resize(msgHeaderSize + msg.payload.size());

		const uint8_t* headerPtr = reinterpret_cast<const uint8_t*>(&msg.header);
		std::copy(headerPtr, headerPtr + msgHeaderSize, to.begin());
		std::copy(msg.payload.begin(), msg.payload.end(), to.begin() + msgHeaderSize);
	}

	void deserialize(std::vector <uint8_t> buffer, SMAProtocol& msg)
	{
		size_t msgHeaderSize = sizeof(msg.header);

		if (buffer.size() < msgHeaderSize)
		{
			throw std::runtime_error("buffer size is too small for header");
		}

		std::memcpy(&msg.header, buffer.data(), msgHeaderSize);

		if (msg.header.type < SMAProtocolType::TEXT || msg.header.type > SMAProtocolType::COMMAND) {
			throw std::runtime_error("Error message type");
		}

		if (buffer.size() < msgHeaderSize + msg.header.payloadSize) {
			throw std::runtime_error("Payload size mismatch");
		}

		msg.payload.assign
		(
			buffer.begin() + msgHeaderSize,
			buffer.begin() + msgHeaderSize + msg.header.payloadSize
		);
	}
}