#pragma once

#include <string>
#include <vector>
#include <iostream>

#include "GameLogic.h"
#include "Location.hpp"

#include <boost/algorithm/string.hpp>

using std::string;
using vecstr = std::vector<std::string>;
using namespace boost::algorithm;

class CommandRemouter
{
public:
	CommandRemouter();
	void onNewCommandArgs(vecstr& args);
	GameLogic _gameLogic;

private:
	vecstr valid_nums = {"A", "B", "C", "D", "E", "F", "G", "H"};
	vecstr valid_words = {"1", "2", "3", "4", "5", "6", "7", "8" };

	vecstr valid_poses;
};

