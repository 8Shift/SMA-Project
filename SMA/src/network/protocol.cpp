#include <vector>
#include <stdexcept>

#include "protocol.h"
#include "crc32.h"

namespace Protocol
{
	void serialize(SMAProtocol msg, std::vector<uint8_t>& to) 
	{
		size_t msgHeaderSize = sizeof(msg.header);

		
		msg.header.checksum = calculateCrc32(msg.payload);

		to.clear();
		to.resize(msgHeaderSize + msg.payload.size());

		const uint8_t* headerPtr = reinterpret_cast<const uint8_t*>(&msg.header);
		std::copy(headerPtr, headerPtr + msgHeaderSize, to.begin());
		std::copy(msg.payload.begin(), msg.payload.end(), to.begin() + msgHeaderSize);
	}

    void deserialize(std::vector<uint8_t> buffer, SMAProtocol& msg)
    {
        size_t msgHeaderSize = sizeof(msg.header);

        if (buffer.size() < msgHeaderSize)
        {
            throw std::runtime_error("Buffer size is too small for header");
        }

        std::memcpy(&msg.header, buffer.data(), msgHeaderSize);

        if (msg.header.type < SMAProtocolType::TEXT || msg.header.type > SMAProtocolType::COMMAND)
        {
            throw std::runtime_error("Invalid message type");
        }

        if (buffer.size() < msgHeaderSize + msg.header.payloadSize)
        {
            throw std::runtime_error("Payload size mismatch");
        }

        msg.payload.assign
        (
            buffer.begin() + msgHeaderSize,
            buffer.begin() + msgHeaderSize + msg.header.payloadSize
        );

        uint32_t calculatedChecksum = calculateCrc32(msg.payload);

        if (msg.header.checksum != calculatedChecksum)
        {
            throw std::runtime_error("Checksum verification failed (data corrupted) | Recommended to check connection");
        }
    }
}