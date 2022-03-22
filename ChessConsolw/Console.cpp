#include "Console.h"

void Console::println(std::string s)
{
	std::cout << s << std::endl;
}

void Console::print()
{
}

std::vector<std::string> Console::getConsoleArgs()
{
	const char* str;
	std::string n = "";
	std::getline(std::cin, n);
	str = n.c_str();

	std::vector<std::string> args;

	//код спизжен и не изетсно как работает но работает
	do
	{
		const char* begin = str;

		while (*str != ' ' && *str)
			str++;

		args.push_back(std::string(begin, str));
	} while (0 != *str++);

	return args;
}
