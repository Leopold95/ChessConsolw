#include "GameLogic.h"

GameLogic::GameLogic()
{
}

GameLogic::GameLogic(PieceManager& pieceManager)
{
	this->pieceManager = pieceManager;
}

void GameLogic::tryMovePiece(Location loc1, Location loc2)
{
	Location locToMove;
	string id;

	//�������� � ������ ���������� ������ 
	for (const auto& item : Desk::GetInstanse().Pieces)
	{
		if (item.second->CurrentLocation() == loc1) 
		{
			if (item.second->CurrentColor() == Color::White)
			{
				std::cout << "������� ������ ����" << std::endl;
				id = item.first;
				break;
			}
		}
	}

	//�������� ������� ��������� 
	for (const auto& item : Desk::GetInstanse().Pieces)
	{
		if (item.second->CurrentLocation() != loc2) continue;
		else std::cout << "�� ������ ����� ���� ������" << std::endl;
	}

	//����������� ������
	std::cout << "������ ����������" << std::endl;
	Desk::GetInstanse().Pieces[id]->CurrentLocation() = loc2;

	for (const auto& item : Desk::GetInstanse().Pieces)
	{
		if (item.second->CurrentLocation() == loc2)
		{
			std::cout << "��������� ������ �������� 1  " << item.first << std::endl;
		}

		if (item.first == id)
		{
			std::cout << "��������� ������ �������� 2  " << item.first << std::endl;
		}
	}
}

void GameLogic::killPiece(Piece& piece)
{
	piece.Kill();
}

Piece& GameLogic::getPieceFromLocation(Location loc)
{
	for (auto& item : Desk::GetInstanse().Pieces)
	{
		if (item.second->CurrentLocation() == loc)
		{
			return *item.second;
		}		
	}

	throw new std::exception("didnt find any valid location");

	Pawn p = Pawn(PieceList::None, Color::None, Location(), false);

	return p; 
}

void GameLogic::movePiece(string idWhoMove, Location placeToMove)
{
	for (auto& item : Desk::GetInstanse().Pieces)
		if (item.first == idWhoMove)
			item.second->CurrentLocation() = placeToMove;
}

