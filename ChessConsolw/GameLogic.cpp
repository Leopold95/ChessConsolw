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
	for (const auto item : Desk::GetInstanse().Pieces)
	{
		if (item.second->CurrentLocation() == loc1)
			if (item.second->CurrentColor() == Color::White) 
				std::cout << "Союзнаа фигура есть" << std::endl;

		if (item.second->CurrentLocation() == loc2)
			if (item.second->CurrentColor() == Color::Black) //вражеская фигур есть
			{
				killPiece();
			}
	}

}

void GameLogic::killPiece(Piece& piece)
{
	
}

template<typename P>
inline P GameLogic::getPieceFromLocation(Location loc)
{
	Piece& p;

	for (auto& item : Desk::GetInstanse().Pieces)
	{
		if (item.second->CurrentLocation() == loc)
		{
			return item.second;
		}		
	}

	throw new std::exception("didnt find any valid location");

	return p;
}

