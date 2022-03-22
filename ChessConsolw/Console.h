#pragma once

#include <iostream>
#include <string>
#include <vector>

class Console
{
public:
	static void println(std::string);
	static void print();
	static std::vector<std::string> getConsoleArgs();
};

