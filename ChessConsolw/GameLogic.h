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
	Desk& _desk = Desk::GetInstanse();

	void makeMove(string idWhoMove, Location& placeToMove);
	void movePieceToKill(string idWhoMove, Location& placeToMove);
	bool isCellEmpty(const Location& loc);
	Piece* getPieceById(string id);
	PieceList getPieceByLocation(Location loc);

	const std::string CELL_FREE = " ";
	const std::string CELL_OCCUPIED = "1";
};