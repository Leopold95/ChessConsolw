#pragma once

#include "Desk.h"
#include "PieceManager.h"
#include "GameLogic.h"

class Game
{
public:
	void startNewGame();
	void endCurrentGame();

	~Game();

private:
	Desk* _desk = new Desk();
	PieceManager* _pieceManager = new PieceManager();
	GameLogic* _gameLogic = new GameLogic();
};

