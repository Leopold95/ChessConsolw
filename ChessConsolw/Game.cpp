#include "Game.h"

Game::~Game()
{
	delete desk;
}

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



