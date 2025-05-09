#include <fstream>
#include <optional>
#include <source_location>

#include "logger.h"

class FileLogger : public ILogger
{
private:
	std::ofstream logfile;
public:
	FileLogger() = default;
	FileLogger(const std::string& logfileName); 
	FileLogger(const FileLogger& other) = delete;
	FileLogger(FileLogger&& rvalue) = delete;

	virtual ~FileLogger();

	void log(LogLevel lvl, const std::string& message, const std::source_location& location = std::source_location::current()) override;

	void setLogFileName(const std::string& logfileName);
};