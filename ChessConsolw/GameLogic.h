#pragma once

#include "Location.hpp"
#include "Desk.h"
#include "PieceManager.h"
#include "EmptyPiece.hpp"
#include "Console.h"

#include <iostream>
#include <string>

using std::string;

class GameLogic
{
public:
	GameLogic();
	GameLogic(PieceManager& pieceManager);

	void tryMovePiece(Location loc1, Location loñ2);
	void killPiece(Piece& piece);

private:
	PieceManager pieceManager;


	//Piece* pieceToMove;

	Piece& getPieceFromLocation(Location loc);
	void movePiece(string idWhoMove, Location placeToMove);
};