#pragma once

#include <string>
#include <vector>
#include <iostream>

#include "Piece.hpp"
#include "PieceList.hpp"
#include "SystemVariables.h"

#include <boost/algorithm/string.hpp>


using std::string;

using vecstr = std::vector<std::string>;

class CommandRemouter
{
public:
	void onNewCommand(short c);
	void onNewCommand(std::string c);
	void onNewCommandArgs(vecstr& args);
	void clearConsole();
	void printCommands();

private:
	inline void print(string s);
	inline void printPiece(PieceList);
	
	void printRules();

	//SystemVariables& sv = SystemVariables::GetInstanse();
};

