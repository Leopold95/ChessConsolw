#pragma once

#include "Piece.hpp"
#include "PieceList.hpp"
#include "Utils.hpp"
#include "SystemVariables.h"
#include "Location.hpp"

#include "boost/algorithm/string.hpp"

#include <string>
#include <exception>

using std::string;

class GameManager
{
public:
	void movePiece(string firstPos, string secondPos);
	void movePiece(Location& firstPos, Location& secondPos);

private:
	//SystemVariables& sv = SystemVariables::GetInstanse();
};

