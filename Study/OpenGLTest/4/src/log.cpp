#include "../lib/log.h"

void Logger::Log(std::string type, std::string content)
{
	std::printf("%s %s\n", type.c_str(), content.c_str());
}
