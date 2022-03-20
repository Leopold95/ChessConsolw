#pragma once

#include <unordered_map>
#include <string>
#include <vector>
#include <exception>

#include "Pieces.hpp"
#include "MoveType.hpp"

class PieceManager
{
public:
	PieceManager();

	//void tryMovePiece(Location loc1, Location loс2);

	//"учит" фигуру "ходить" на доске
	void buildPieceMoveTypes(std::unordered_map<PieceList, std::vector<MoveType>>& mp);
	std::unordered_map<PieceList, std::vector<MoveType>> buildPieceMoveTypes();

	// задать для каждой фигуры на доске начальное стандартное положение
	void placeStarterPieceOnDesk(std::unordered_map<std::string, Piece*>& mp);
	std::unordered_map<std::string, Piece*> placeStarterPieceOnDesk();

private:
	//std::unordered_map<std::string, Piece*> piecesOnDeskMap; //словарь положения и полной информации каждой фигуры на доске
	std::unordered_map<PieceList, std::vector<MoveType>> pieceMoveTypes; 	//словарь фигуры и ее типов движений

	std::string generateRandomString();

	template <typename T>
	T getPieceFromLocation(Location loc);
};

