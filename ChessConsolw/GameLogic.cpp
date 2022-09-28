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



	//проверка второго положения 
	if (isCellEmpty(loc2) == false)
		makeMove(id, loc2);
	else
	{

	}

	//работаем с типом фигуры полученным из ее положения
	switch (getPiceType(loc1))
	{		
	case PieceList::Pawn:
		if(_movesCalcer.canPawnMoveTo(loc1, loc2))
			makeMove(id, loc2);
		break;

	case PieceList::King:
		if (_movesCalcer.canKingMoveTo(loc1, loc2))
			makeMove(id, loc2);
		break;

	case PieceList::Queen:
		break;

	case PieceList::Rook:
		if (_movesCalcer.canRookMoveTo(loc1, loc2))
			makeMove(id, loc2);
		break;

	case PieceList::Knight:
		break;

	case PieceList::Bishop:
		break;

		//TODO create default return value
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

int GameLogic::letterToInt(std::string letter)
{
	if (iequals(letter, "a") || iequals(letter, "A"))
		return 1;

	if (iequals(letter, "b") || iequals(letter, "B"))
		return 2;

	if (iequals(letter, "c") || iequals(letter, "C"))
		return 3;

	if (iequals(letter, "d") || iequals(letter, "D"))
		return 4; 

	if (iequals(letter, "e") || iequals(letter, "E"))
		return 5;

	if (iequals(letter, "f") || iequals(letter, "F"))
		return 6;

	if (iequals(letter, "g") || iequals(letter, "G"))
		return 7;

	if (iequals(letter, "h") || iequals(letter, "H"))
		return 8;

	return 0;
}

void GameLogic::makeMove(string idWhoMove, Location& placeToMove)
{
	Location loc = Desk::GetInstanse().Pieces.at(idWhoMove)->CurrentLocation();
	_gameSound->sound_movePiece.play();
	getPiece(idWhoMove)->CurrentLocation() = placeToMove;
}

void GameLogic::movePieceToKill(string idWhoMove, Location& placeToMove)
{
	Piece* secPiece = getPiece(placeToMove);
	secPiece->Kill();

	makeMove(idWhoMove, placeToMove);
}

bool GameLogic::isCellEmpty(const Location& loc)
{
	if(_desk.PiecesOnPritebleDesk_mask[loc.y][loc.x] == CELL_OCCUPIED)
		return false;

	return true;
}

bool GameLogic::isPieceExistAt(const Location& loc)
{
	Piece* p = getPiece(loc);

	if (p->CurrentLocation() == loc)
		return true;

	return false;
}

Piece* GameLogic::getPiece(string id)
{
	return Desk::GetInstanse().Pieces[id];
}

Piece* GameLogic::getPiece(Location loc)
{
	for (auto& [id, piece] : _desk.Pieces)
		if (piece->CurrentLocation() == loc)
			return piece;

	throw new std::exception("No piece at requared location.");

	return new EmptyPiece();
}

PieceList GameLogic::getPiceType(Location loc)
{
	for (auto& item : _desk.Pieces)
		if (item.second->CurrentLocation() == loc)
			return item.second->CurrentPiece();

	return PieceList();
}

