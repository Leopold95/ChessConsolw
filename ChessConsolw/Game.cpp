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

	runGameLoop();
}

void Game::endCurrentGame()
{
	system("CLS");
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
	//заполнение доски пустотой
	for (const auto& piece : _desk.Pieces)
	{
		int x = piece.second->CurrentLocation().x;
		int y = piece.second->CurrentLocation().y;

		_desk.PritebleDesk[y][x] = " ";
	}
		
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