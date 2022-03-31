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

	//работаем с первым положением фигуры 
	for (const auto& item : Desk::GetInstanse().Pieces)
	{
		if (item.second->CurrentLocation() == loc1) 
		{
			if (item.second->CurrentColor() == Color::White)
			{
				std::cout << "Союзнаа фигура есть" << std::endl;
				id = item.first;
				break;
			}
		}
	}

	//проверка второго положения 
	for (const auto& item : Desk::GetInstanse().Pieces)
	{
		if (item.second->CurrentLocation() != loc2) continue;
		else std::cout << "Во втором месте етсь фигура" << std::endl;
	}

	//перемещение фигуры
	std::cout << "фигура перемещена" << std::endl;
	Desk::GetInstanse().Pieces[id]->CurrentLocation() = loc2;

	for (const auto& item : Desk::GetInstanse().Pieces)
	{
		if (item.second->CurrentLocation() == loc2)
		{
			std::cout << "положение фигуры изменено 1  " << item.first << std::endl;
		}

		if (item.first == id)
		{
			std::cout << "положение фигуры изменено 2  " << item.first << std::endl;
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

