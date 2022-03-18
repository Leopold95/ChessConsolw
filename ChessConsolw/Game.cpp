#include "Game.h"

void Game::startNewGame()
{
	system("CLS");
	desk->print(DeskType::Default);
}

void Game::endCurrentGame()
{
	system("CLS");
	Utils::println("ќжидание игры...");
}

