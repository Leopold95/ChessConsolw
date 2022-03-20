#pragma once

#include <unordered_map>
#include <string>
#include <vector>

#include "Pieces.hpp"
#include "MoveType.hpp"

class PieceManager
{
public:
	PieceManager();

	void tryMovePiece(Location loc1, Location lo�2);

	//"����" ������ "������" �� �����
	void buildPieceMoveTypes(std::unordered_map<PieceList, std::vector<MoveType>>& mp);
	std::unordered_map<PieceList, std::vector<MoveType>> buildPieceMoveTypes()
	{
		std::unordered_map<PieceList, std::vector<MoveType>> mp;

		buildPieceMoveTypes(mp);

		return mp;
	}

	// ������ ��� ������ ������ �� ����� ��������� ����������� ���������
	void placeStarterPieceOnDesk(std::unordered_map<std::string, Piece*>& mp);
	std::unordered_map<std::string, Piece*> placeStarterPieceOnDesk();

private:
	std::unordered_map<std::string, Piece*> piecesOnDeskMap; //������� ��������� � ������ ���������� ������ ������ �� �����
	std::unordered_map<PieceList, std::vector<MoveType>> pieceMoveTypes; 	//������� ������ � �� ����� ��������

	std::string generateRandomString();

	template <typename T>
	T getPieceFromLocation(Location loc);
};

