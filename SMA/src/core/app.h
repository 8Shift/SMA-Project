#pragma once

#include <memory>

#include "uuid_v4.h"

#include "../network/transportprotocol.h"
#include "../gui/gui.h"
#include "profile.h"

class IApplication
{
private:
	std::unique_ptr <ITransport> transport;
	std::unique_ptr <Gui> gui;
	std::unique_ptr <ClientProfile> profile;
	UUIDv4::UUID uuid;
	UUIDv4::UUIDGenerator<std::mt19937_64> uuidGenerator;
public:
	virtual int start() = 0;
	
	Gui* getGui() const;
};