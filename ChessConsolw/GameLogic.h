#pragma once

#include "Location.hpp"
#include "Desk.h"
#include "PieceManager.h"

class GameLogic
{
public:
	GameLogic();
	GameLogic(Desk& desk, PieceManager& pieceManager);

	void tryMovePiece(Location loc1, Location loñ2);

private:
	Desk desk;
	PieceManager pieceManager;
};

