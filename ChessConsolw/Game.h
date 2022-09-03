#pragma once

#include "Desk.h"
#include "PieceManager.h"
#include "GameLogic.h"
#include "Utils.hpp"
#include "CommandRemouter.h"
#include "Console.h"

class Game
{
public:
	void startNewGame();
	void endCurrentGame();

	bool isGameRunning = false;

	~Game();

private:
	Desk& _desk = Desk::GetInstanse();
	PieceManager _pieceManager;
	GameLogic _gameLogic;
	CommandRemouter _commandRemouter;

	void initialise();
	void runGameLoop();
	void updatePrintebleDesk();
};

