#include <format>
#include <iomanip>

#include "streamlogger.h"

void StreamLogger::log(LogLevel lvl, const std::string& message, const std::source_location& location)
{
	auto& [lglvl, col] = LogLevelTable[lvl];

	std::string fileName = location.file_name();
	std::string functionName = location.function_name();
	std::string line = std::to_string(location.line());
	std::string column = std::to_string(location.column());

	std::cout << col.construct(lglvl) << " " << std::quoted(fileName.c_str()) << std::format("({}, {})", line, column) << ": In function " << functionName << " " << message << std::endl;
}
