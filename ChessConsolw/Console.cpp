#include "Console.h"

void ConsolePromoute::Console::println(std::string s)
{
	std::cout << s << std::endl;
}


void ConsolePromoute::Console::print()
{
}

void ConsolePromoute::Console::print(std::string s, Color c)
{
	switch (c)
	{
	case ConsolePromoute::Color::WHITE:
		system("Color " + (char)c);
		std::cout << s.c_str();
		break;
	case ConsolePromoute::Color::LIGHTBLUE:
		break;
	case ConsolePromoute::Color::RED:
		break;
	default:
		break;
	}

	system("Color 7");
}

std::vector<std::string> ConsolePromoute::Console::getConsoleArgs()
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
