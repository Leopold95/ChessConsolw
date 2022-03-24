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
	void onNewCommandArgs(vecstr& args);
	GameLogic _gameLogic;
};

