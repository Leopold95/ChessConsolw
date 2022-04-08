#pragma once

#include <iostream>
#include <string>
#include <vector>
namespace ConsolePromoute
{
	enum class Color : char
	{
		WHITE = 7,
		LIGHTBLUE = 9,
		RED = 4
	};

	class Console
	{
	public:
		static void println(std::string);
		static void print();
		static void print(std::string, Color);
		static std::vector<std::string> getConsoleArgs();
	};
};


