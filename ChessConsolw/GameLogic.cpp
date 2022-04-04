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
	string id;

	//работаем с первым положением фигуры 
	for (const auto& item : Desk::GetInstanse().Pieces)
	{
		if (item.second->CurrentLocation() == loc1) 
		{
			if (item.second->CurrentColor() == Color::White) //Союзнаа фигура есть
			{
				id = item.first;
				break;
			}
		}
	}

	bool isFree = false;
	//проверка второго положения 
	for (const auto& item : Desk::GetInstanse().Pieces)
	{
		if (item.second->CurrentLocation() != loc2) //нету фигуры
			isFree = true;
		else //фигура обнаружена
			isFree = false;
	}


	//работаем с типом фигуры полученным из ее положения
	switch (getPieceByLocation(loc1))
	{		
	case PieceList::Pawn:
		if(_movesCalcer.canPawnMoveTo(loc1, loc2))
			movePiece(id, loc2);
		break;

	case PieceList::King:
		if (_movesCalcer.canKingMoveTo(loc1, loc2))
			movePiece(id, loc2);
		break;

	case PieceList::Queen:
		break;

	case PieceList::Rook:
		if (_movesCalcer.canRookMoveTo(loc1, loc2))
			movePiece(id, loc2);
		break;

	case PieceList::Knight:
		break;

	case PieceList::Bishop:
		break;

	default:
		break;
	}

	//if (isFree) movePiece(id, loc2);
	//else movePieceToKill(id, loc2);
}

void GameLogic::killPiece(Piece& piece)
{
	piece.Kill();
}

void GameLogic::movePiece(string idWhoMove, Location& placeToMove)
{
	getPieceById(idWhoMove)->CurrentLocation() = placeToMove;
}

void GameLogic::movePieceToKill(string idWhoMove, Location& placeToMove)
{
	Piece* piece = getPieceById(idWhoMove);


}

Piece* GameLogic::getPieceById(string id)
{
	return Desk::GetInstanse().Pieces[id];
}

PieceList GameLogic::getPieceByLocation(Location loc)
{
	for (auto& item : Desk::GetInstanse().Pieces)
		if (item.second->CurrentLocation() == loc)
			return item.second->CurrentPiece();

	return PieceList::None;
}

