#pragma once

#include <memory>

#include "uuid_v4.h"

#include "../network/transportprotocol.h"
#include "filelogger.h"
#include "streamlogger.h"
#include "profile.h"

class IApplication
{
protected:
	std::unique_ptr <ITransport> transport;
	std::unique_ptr <ClientProfile> profile;
	FileLogger flogger;
	StreamLogger slogger;
	UUIDv4::UUID uuid;
	UUIDv4::UUIDGenerator<std::mt19937_64> uuidGenerator;
public:
	IApplication() = default;
	IApplication(const IApplication& other) = delete;
	IApplication(IApplication&& rvalue) = delete;

	virtual ~IApplication() = default;

	virtual int fExit() = 0;

	virtual int exec() = 0;


	virtual void setProtocol(std::string_view type) = 0;
};