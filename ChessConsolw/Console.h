#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Color.hpp"


namespace ConsolePromoute
{
	class Console
	{
	public:
		static std::vector<std::string> getConsoleArgs();

		void serCursorPos(int x, int y);
		void printWhite(char piece);
		void printBlack(char piece);
	};
};


