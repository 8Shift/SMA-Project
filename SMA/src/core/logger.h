#pragma once

#include <iostream>
#include <map>
#include <source_location>
#include <string>

enum class LogLevel
{
	TRACE,
	DEBUG,
	INFO,
	WARN,
	ERR,
	FATAL
};

struct StreamColor
{
	int fontmod{0};
	int bcolormod{40};
	int tcolormod{37};

	StreamColor() = default;
	StreamColor(int f, int b, int s) : fontmod(f), bcolormod(b), tcolormod(s) {};

	std::string construct(const std::string& text);
};

extern std::map <LogLevel, std::pair<std::string, StreamColor>> LogLevelTable;

class ILogger
{
public:
	ILogger() = default;
	ILogger(const ILogger& other) = default;
	ILogger(ILogger&& rval) = delete;
	virtual ~ILogger() = default;

public:
	virtual void log(LogLevel lvl, const std::string& message, const std::source_location& location = std::source_location::current()) = 0;
};