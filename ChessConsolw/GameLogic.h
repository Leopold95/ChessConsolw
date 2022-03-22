#pragma once

#include "Location.hpp"
#include "Desk.h"
#include "PieceManager.h"

#include <iostream>

class GameLogic
{
public:
	GameLogic();
	GameLogic(PieceManager& pieceManager);

	void tryMovePiece(Location loc1, Location loñ2);
	void killPiece(Piece& piece);

private:
	PieceManager pieceManager;

	template<typename P>
	P getPieceFromLocation(Location loc);
};