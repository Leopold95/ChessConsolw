#pragma once

#include "Location.hpp"
#include "Desk.h"
#include "PieceManager.h"
#include "EmptyPiece.hpp"
#include "Console.h"
#include "MovesCalculator.h"
#include "Pieces.hpp"

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
	MovesCalculator _movesCalcer;

	void movePiece(string idWhoMove, Location& placeToMove);
	void movePieceToKill(string idWhoMove, Location& placeToMove);
	Piece* getPieceById(string id);
	PieceList getPieceByLocation(Location loc);
};