#pragma once

#include <unordered_map>
#include <string>
#include <vector>

#include "Pieces.hpp"
#include "MoveType.hpp"
//#include "Utils.hpp"

class PieceManager
{
public:
	void tryMovePiece(Location loc1, Location loс2);

	//"учит" фигуру "ходить" на доске
	void buildPieceMoveTypes(std::unordered_map<PieceList, std::vector<MoveType>>& mp);

	// задать для каждой фигуры на доске начальное стандартное положение
	void placeStarterPieceOnDesk(std::unordered_map<std::string, Piece*>& mp);

private:
	std::string generateRandomString();

	template <typename T>
	T getPieceFromLocation(Location loc);
};

