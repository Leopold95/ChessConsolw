#include "Game.h"

Game::~Game()
{
	delete desk;
}

void Game::startNewGame()
{
	system("CLS");

	for (const auto& piece : desk->Pieces)
	{
		int a = piece.second->CurrentLocation().x;
		int b = piece.second->CurrentLocation().y;

		desk->PritebleDesk[b][a] = (char)piece.second->CurrentPiece();
	}

	desk->print(desk->PritebleDesk);

	Location testLocation(2, 4);
	Location testLocation2(5, 6);

	//Location testLoc(9, 8);

	//if()

}

void Game::endCurrentGame()
{
	system("CLS");
	Utils::println("ќжидание игры...");
}



