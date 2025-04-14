#pragma once

#include <iostream>
#include <string>

enum class LogMode;
enum class LogLevel;

class Logger
{
private:
	LogMode mode;
public:
	Logger() = default;
	Logger(LogMode mode) : mode(mode) {};
	Logger(const Logger& other) = default;
	Logger(Logger&& rval) = delete;
	virtual ~Logger() = default;

public:
	void log(LogLevel lvl, std::string message);

	void setLogMode(LogMode mode);
};