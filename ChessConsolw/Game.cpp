#include "Game.h"

Game::~Game()
{
	delete _pieceManager;
	delete _gameLogic;
	delete _commandRemouter;
}

void Game::startNewGame()
{
	initialise();

	isGameRunning = true;

	runGameLoop();
}

void Game::endCurrentGame()
{
	system("CLS");
	isGameRunning = false;
}

void Game::initialise()
{
	//заполнение доски для вывода из стандартного пустого шаблона
	for (size_t i = 0; i < 9; i++)
		for (size_t j = 0; j < 9; j++)
			_desk.PritebleDesk[i][j] = _desk._fullyCrearPritrbleDesk[i][j];

	//заполение доски для вывода стандартным щалоном
	_desk.Pieces = _desk.DefaultPieces;

	//заполенеие доски для вывода из стандартного шаблона
	for (const auto& piece : _desk.DefaultPieces)
	{
		int x = piece.second->CurrentLocation().x;
		int y = piece.second->CurrentLocation().y;

		_desk.PritebleDesk[y][x] = (char)piece.second->CurrentPiece();
	}
}

void Game::updatePrintebleDesk()
{
	//очищение доски
	for (size_t i = 1; i <= 8; i++)
		for (size_t j = 1; j <= 8; j++)
			_desk.PritebleDesk[j][i] = " ";
	
	//перезаполнение доски для вывода из текущей карты фигур на доске
	for (const auto& piece : _desk.Pieces)
	{
		int x = piece.second->CurrentLocation().x;
		int y = piece.second->CurrentLocation().y;

		if(piece.second->IsAlive())
			_desk.PritebleDesk[y][x] = (char)piece.second->CurrentPiece();
	}
}

void Game::runGameLoop()
{
	_desk.print(_desk.PritebleDesk);

	std::vector<std::string> args = Console::getConsoleArgs();
	_commandRemouter->onNewCommandArgs(args);

	updatePrintebleDesk();

	_desk.print(_desk.PritebleDesk);
}