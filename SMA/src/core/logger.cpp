#include <unordered_map>

#include "logger.h"

enum class LogMode
{
	CONSOLE,
	FILE,
	ALL
};

enum class LogLevel
{
	TRACE,
	DEBUG,
	INFO,
	WARN,
	ERROR,
	FATAL
};

const std::unordered_map <LogLevel, std::string> strLvl = 
{
{LogLevel::TRACE, "[TRACE] "},
{LogLevel::DEBUG, "[DEBUG] "},
{LogLevel::INFO,  "[INFO]  "},
{LogLevel::WARN,  "[WARN]  "},
{LogLevel::ERROR, "[ERROR] "},
{LogLevel::FATAL, "[FATAL] "}
};

void Logger::log(LogLevel lvl, std::string message)
{
	auto it = strLvl.find(lvl);
	switch (mode)
	{
	case LogMode::CONSOLE:
		if (it != strLvl.end())
		{
			std::cout << it->second << message << std::endl;
		}
		break;
	case LogMode::FILE:
		break;
	case LogMode::ALL:
		break;
	}
}

void Logger::setLogMode(LogMode mode)
{
	this->mode = mode;
}
