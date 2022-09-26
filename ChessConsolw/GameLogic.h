#pragma once

#include "Location.hpp"
#include "Desk.h"
#include "PieceManager.h"
#include "EmptyPiece.hpp"
#include "Console.h"
#include "MovesCalculator.h"
#include "Pieces.hpp"
#include "GameSound.h"
#include "Structs.hpp"

#include <boost/algorithm/string.hpp>

#include <string>

using std::string;
using namespace boost::algorithm;

class GameLogic
{
public:
	GameLogic();
	GameLogic(PieceManager& pieceManager);

	void tryMovePiece(Location loc1, Location loñ2);
	void killPiece(Piece& piece);
	int letterToInt(std::string letter);

private:
	PieceManager pieceManager;
	MovesCalculator _movesCalcer;
	Desk& _desk = Desk::GetInstanse();
	GameSound* _gameSound = GameSound::Instanse();
	Structs::SoundList soundList;

	void makeMove(string idWhoMove, Location& placeToMove);
	void movePieceToKill(string idWhoMove, Location& placeToMove);
	bool isCellEmpty(const Location& loc);
	Piece* getPieceById(string id);
	PieceList getPieceByLocation(Location loc); //TODO what is this (make normal piece checker)

	const std::string CELL_FREE = " ";
	const std::string CELL_OCCUPIED = "1";
};