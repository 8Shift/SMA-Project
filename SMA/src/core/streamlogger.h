#include <iostream>

#include "logger.h"

class StreamLogger : public ILogger
{
public:
	void log(LogLevel lvl, const std::string& message, const std::source_location& location = std::source_location::current()) override;
};