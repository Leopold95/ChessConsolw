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
		int a = piece.second->CurrentLocation().x;
		int b = piece.second->CurrentLocation().y;

		_desk->PritebleDesk[b][a] = (char)piece.second->CurrentPiece();
	}

	_desk->print(_desk->PritebleDesk);
}

void Game::endCurrentGame()
{
	system("CLS");
}



