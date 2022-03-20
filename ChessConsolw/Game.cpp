#include "Game.h"

Game::~Game()
{
	delete desk;
}

void Game::startNewGame()
{
	system("CLS");

	for (const auto& piece : sv.getPiecesOnDeskMap())
	{
		int a = piece.second->CurrentLocation().x;
		int b = piece.second->CurrentLocation().y;

		desk->clearDeskTemplate[b][a] = (char)piece.second->CurrentPiece();
	}

	desk->print(desk->clearDeskTemplate);


}

void Game::endCurrentGame()
{
	system("CLS");
	Utils::println("ќжидание игры...");
}



