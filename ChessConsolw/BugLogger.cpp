#include "BugLogger.h"

void BugLogger::addLog(std::string log)
{
	std::ofstream file;
	file.open("Logs.txt");
	file << log;
	file.close();
}
