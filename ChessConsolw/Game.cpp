#include "Game.h"

Game::~Game()
{
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
	for (const auto&[id, piece] : _desk.DefaultPieces)
	{
		int x = piece->CurrentLocation().x;
		int y = piece->CurrentLocation().y;

		_desk.PritebleDesk[y][x] = (char)piece->CurrentPiece();
	}
}

void Game::updatePrintebleDesk()
{
	//очистка игровой доски
	for (size_t i = 1; i <= 8; i++) 
		for (size_t j = 1; j <= 8; j++)
			_desk.PritebleDesk[j][i] = " "; 

	//очиска маски с фигурами
	for (size_t i = 0; i < 8; i++)
		for (size_t j = 0; j < 8; j++)
			_desk.PiecesOnPritebleDesk_mask[j][i] = " "; 

	
	//перезаполнение доски для вывода из текущей карты фигур на доске
	for (const auto&[id, piece] : _desk.Pieces)
	{
		short x = piece->CurrentLocation().x;
		short y = piece->CurrentLocation().y;

		if(piece->IsAlive())
			_desk.PritebleDesk[y][x] = (char)piece->CurrentPiece();
	}

	//запление маски с фигурами 
	for (const auto&[id, piece] : _desk.Pieces)
	{
		short x = piece->CurrentLocation().x;
		short y = piece->CurrentLocation().y;

		if (piece->IsAlive())
			_desk.PiecesOnPritebleDesk_mask[y - 1][x - 1] = "1";
	}
}

void Game::runGameLoop()
{
	_desk.print(_desk.PritebleDesk);

	_commandRemouter.handleNewCommand(args);

	updatePrintebleDesk();

	_desk.print(_desk.PritebleDesk);
}