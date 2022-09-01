#pragma once

#include <string>
#include <vector>

#include "GameLogic.h"
#include "Location.hpp"
#include "Console.h"
#include "Logger.hpp"

#include <boost/algorithm/string.hpp>

using std::string;
using vecstr = std::vector<std::string>;
using namespace boost::algorithm;

class CommandRemouter
{
public:
	CommandRemouter();
	~CommandRemouter();
	void onNewCommandArgs(vecstr& args);
	GameLogic _gameLogic;

private:
	const vecstr VALID_LETTERS = {"A", "B", "C", "D", "E", "F", "G", "H"};
	const vecstr VALID_NUMS = {"1", "2", "3", "4", "5", "6", "7", "8"};

	void incorrectCommand();
	bool isValidCommandSyntax(string command, vecstr args);

	vecstr valid_poses;

	Logger* _logger = new Logger();
};

