#include "GameLogic.h"

GameLogic::GameLogic()
{
}

GameLogic::GameLogic(Desk& desk, PieceManager& pieceManager)
{
	this->desk = desk;
	this->pieceManager = pieceManager;
}

void GameLogic::tryMovePiece(Location loc1, Location lo�2)
{
	for (const auto& item : desk.Pieces)
	{
		if (item.second->CurrentLocation() != loc1) throw new std::exception("������ ������ ���� � ������ ���������");
	}
}
