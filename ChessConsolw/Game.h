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

	~Game();

private:
	Desk& _desk = Desk::GetInstanse();
	PieceManager* _pieceManager = new PieceManager();
	GameLogic* _gameLogic = new GameLogic();
	CommandRemouter* _commandRemouter = new CommandRemouter();

	void runGameLoop();
};

