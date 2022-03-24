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
	for (const auto& item : Desk::GetInstanse().Pieces)
	{
		if (item.second->CurrentLocation() == loc1) 
		{
			if (item.second->CurrentColor() == Color::White)
			{
				std::cout << "Союзнаа фигура есть" << std::endl;
			}
			else
			{
				throw new std::exception("союзной фигуры нету в этом месте ");
			}
		}

				

		if (item.second->CurrentLocation() == loc2)
			if (item.second->CurrentColor() == Color::Black) //вражеская фигур есть
			{
				Piece& p = getPieceFromLocation(loc2);
				killPiece(p);
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

