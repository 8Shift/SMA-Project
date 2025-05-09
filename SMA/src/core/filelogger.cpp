#include <iomanip>
#include <format>

#include "filelogger.h"

FileLogger::FileLogger(const std::string& logfileName)
{
	logfile = std::ofstream(logfileName, std::ios::app);

	if (!logfile.is_open())
	{
		throw std::runtime_error("Error opening logging file");
	}
}

FileLogger::~FileLogger()
{
	logfile.close();
}

void FileLogger::log(LogLevel lvl, const std::string& message, const std::source_location& location)
{
	auto& [lglvl, col] = LogLevelTable[lvl];

	std::string fileName = location.file_name();
	std::string functionName = location.function_name();
	std::string line = std::to_string(location.line());
	std::string column = std::to_string(location.column());

	logfile << lglvl << " " << std::quoted(fileName.c_str()) << std::format("({}, {})", line, column) << ": In function " << functionName << " " << message << std::endl;
}

void FileLogger::setLogFileName(const std::string& logfileName)
{
	logfile = std::ofstream(logfileName);

	if (!logfile.is_open())
	{
		throw std::runtime_error("Error opening logging file");
	}
}
