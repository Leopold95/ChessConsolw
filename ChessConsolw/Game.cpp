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
	//���������� ����� ��� ������ �� ������������ ������� �������
	for (size_t i = 0; i < 9; i++)
		for (size_t j = 0; j < 9; j++)
			_desk.PritebleDesk[i][j] = _desk._fullyCrearPritrbleDesk[i][j];

	//��������� ����� ��� ������ ����������� �������
	_desk.Pieces = _desk.DefaultPieces;

	//���������� ����� ��� ������ �� ������������ �������
	for (const auto& piece : _desk.DefaultPieces)
	{
		int x = piece.second->CurrentLocation().x;
		int y = piece.second->CurrentLocation().y;

		_desk.PritebleDesk[y][x] = (char)piece.second->CurrentPiece();
	}
}

void Game::updatePrintebleDesk()
{
	//������� ������� �����
	for (size_t i = 1; i <= 8; i++) 
		for (size_t j = 1; j <= 8; j++)
			_desk.PritebleDesk[j][i] = " "; 

	//������ ����� � ��������
	for (size_t i = 0; i < 8; i++)
		for (size_t j = 0; j < 8; j++)
			_desk.PiecesOnPritebleDesk_mask[j][i] = " "; 

	
	//�������������� ����� ��� ������ �� ������� ����� ����� �� �����
	for (const auto& piece : _desk.Pieces)
	{
		short x = piece.second->CurrentLocation().x;
		short y = piece.second->CurrentLocation().y;

		if(piece.second->IsAlive())
			_desk.PritebleDesk[y][x] = (char)piece.second->CurrentPiece();
	}

	//�������� ����� � �������� 
	for (const auto& item : _desk.Pieces)
	{
		short x = item.second->CurrentLocation().x;
		short y = item.second->CurrentLocation().y;

		if (item.second->IsAlive())
			_desk.PiecesOnPritebleDesk_mask[y - 1][x - 1] = "1";
	}
}

void Game::runGameLoop()
{
	_desk.print(_desk.PritebleDesk);

	std::vector<std::string> args = ConsolePromoute::Console::getConsoleArgs();
	_commandRemouter.onNewCommandArgs(args);

	updatePrintebleDesk();

	_desk.print(_desk.PritebleDesk);
}