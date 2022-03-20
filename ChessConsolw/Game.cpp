#include "Game.h"

Game::~Game()
{
	delete _desk;
}

void Game::startNewGame()
{
	system("CLS");

	for (const auto& piece : _desk->Pieces)
	{
		int x = piece.second->CurrentLocation().x;
		int y = piece.second->CurrentLocation().y;

		_desk->PritebleDesk[y][x] = (char)piece.second->CurrentPiece();
	}

	_desk->print(_desk->PritebleDesk);

	_gameLogic->tryMovePiece(Location(1, 8), Location(1, 7));
}

void Game::endCurrentGame()
{
	system("CLS");
}



