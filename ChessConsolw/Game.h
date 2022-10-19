#pragma once

#include "Desk.h"
#include "PieceManager.h"
#include "GameLogic.h"
#include "Utils.hpp"
#include "CommandRemouter.h"
#include "Console.h"
#include "GameSound.h"

class Game
{
public:
	void startNewGame();
	void endCurrentGame();

	bool isGameRunning = false;

	~Game();

private:
	Desk& _desk = Desk::GetInstanse();
	GameSound* _gameSound = GameSound::Instanse();
	CommandRemouter _commandRemouter;
	PieceManager _pieceManager;
	GameLogic _gameLogic;
	ConsolePromoute::Console _console;

	void initialise();
	void runGameLoop();
	void updatePrintebleDesk();
};

