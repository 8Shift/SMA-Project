#include <format>

#include "logger.h"

std::map <LogLevel, std::pair<std::string, StreamColor>> LogLevelTable
{
	{LogLevel::TRACE, { "[TRACE]", StreamColor{1,34,40} }},
	{ LogLevel::DEBUG, {"[DEBUG]", StreamColor{1,32,40}} },
	{ LogLevel::INFO, {"[INFO]", StreamColor{1,36,40}} },
	{ LogLevel::WARN, {"[WARN]", StreamColor{1,33,40}} },
	{ LogLevel::ERR, {"[ERR]",StreamColor{1,35,40}} },
	{ LogLevel::FATAL, {"[FATAL]", StreamColor{1,31,40}} },
};

std::string StreamColor::construct(const std::string& text)
{
	std::string tcolormodstr = std::to_string(tcolormod);
	std::string bcolormodstr = std::to_string(bcolormod);
	std::string fontmodstr = std::to_string(fontmod);
	const std::string slicer = ";";

	std::string startColor = std::format("\033[{};{};{}m", tcolormodstr, bcolormodstr, fontmodstr);
	std::string retColor = "\033[0m";

	return startColor + text + retColor;
};
