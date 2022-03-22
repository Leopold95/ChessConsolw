#include "Game.h"

Game::~Game()
{
	delete _pieceManager;
	delete _gameLogic;
	delete _commandRemouter;
}

void Game::runGameLoop()
{
	while (true)
	{
		_desk.print(_desk.PritebleDesk);

		std::vector<std::string> args = Console::getConsoleArgs();
		_commandRemouter->onNewCommandArgs(args);
	}
}

void Game::startNewGame()
{
	//инициализация начального положения фигур
	for (const auto& piece : _desk.Pieces)
	{
		int x = piece.second->CurrentLocation().x;
		int y = piece.second->CurrentLocation().y;

		_desk.PritebleDesk[y][x] = (char)piece.second->CurrentPiece();
	}

	runGameLoop();
}

void Game::endCurrentGame()
{
	system("CLS");
}



