#include "MovesCalculator.h"

MovesCalculator::MovesCalculator()
{
}

bool MovesCalculator::canPawnMoveTo(const Location& fromLocation, Location toLocation)
{
	for (const auto& item : pawnMoves(fromLocation))
		if (item == toLocation) //if one of all possible pawn moves from concrite location = location to move
			return true;

	return false;
}

bool MovesCalculator::canRookMoveTo(const Location& fromLocation, Location toLocation)
{
	for (const auto& item : rookMoves(fromLocation))
		if (item == toLocation) //if one of all possible pawn moves from concrite location = location to move
			return true;

	return false;
}

bool MovesCalculator::canKingMoveTo(const Location& fromLocation, Location toLocation)
{
	for (const auto& item : kingMoves(fromLocation))
		if (item == toLocation) //if one of all possible pawn moves from concrite location = location to move
			return true;

	return false;
}

vector<Location> MovesCalculator::pawnMoves(const Location& currentLocation)
{
	vector<Location> temp;

	//is first move
	bool firstMove = false;
		if (currentLocation.y == FIRST_PAWN_POS) //piece is on first place
			firstMove = true;

	if (firstMove)
	{
		temp.push_back(Location(currentLocation.x, currentLocation.y - 2));
		temp.push_back(Location(currentLocation.x, currentLocation.y - 1));
		temp.push_back(Location(currentLocation.x + 1, currentLocation.y - 1));
		temp.push_back(Location(currentLocation.x - 1, currentLocation.y - 1));
		return temp;
	}

	temp.push_back(Location(currentLocation.x, currentLocation.y - 1));
	temp.push_back(Location(currentLocation.x + 1, currentLocation.y - 1));
	temp.push_back(Location(currentLocation.x - 1, currentLocation.y - 1));

	return temp;
}

vector<Location> MovesCalculator::rookMoves(const Location& currentLocation)
{
	vector<Location> temp;

	for (int i = BOARD_LIMIT_FROM; i <= BOARD_LIMIT_TO; i++) 
	{
		temp.push_back(Location(currentLocation.x, currentLocation.y - i));
		temp.push_back(Location(currentLocation.x, currentLocation.y + i));
		temp.push_back(Location(currentLocation.x + i, currentLocation.y));
		temp.push_back(Location(currentLocation.x - i, currentLocation.y));
	}

	return temp;
}

vector<Location> MovesCalculator::kingMoves(const Location& currentLocation)
{
	vector<Location> temp;

	temp.push_back(Location(currentLocation.x,	   currentLocation.y + 1));
	temp.push_back(Location(currentLocation.x, 	   currentLocation.y - 1));
	temp.push_back(Location(currentLocation.x + 1, currentLocation.y));
	temp.push_back(Location(currentLocation.x - 1, currentLocation.y));

	temp.push_back(Location(currentLocation.x + 1, currentLocation.y + 1));
	temp.push_back(Location(currentLocation.x - 1, currentLocation.y + 1));
	temp.push_back(Location(currentLocation.x + 1, currentLocation.y - 1));
	temp.push_back(Location(currentLocation.x - 1, currentLocation.y - 1));

	return temp;
}


