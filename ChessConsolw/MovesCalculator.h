#pragma once

#include "Location.hpp"
#include <vector>

using std::vector;

class MovesCalculator
{
public:
	MovesCalculator();

	bool canPawnMoveTo(const Location& fromLocation, Location toLocation);
	bool canRookMoveTo(const Location& fromLocation, Location toLocation);
	bool canKingMoveTo(const Location& fromLocation, Location toLocation);

private:
	vector<Location> pawnMoves(const Location& currentLocation);
	vector<Location> rookMoves(const Location& currentLocation);
	vector<Location> kingMoves(const Location& currentLocation);

	const int FIRST_PAWN_POS = 7;
	const int BOARD_LIMIT_FROM = 1;
	const int BOARD_LIMIT_TO = 8;
};

