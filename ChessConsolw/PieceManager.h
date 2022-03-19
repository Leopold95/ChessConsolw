#pragma once

#include <unordered_map>
#include <string>
#include <vector>

#include "Utils.hpp"
#include "Pieces.hpp"
#include "MoveType.hpp"


class PieceManager
{
public:
	void tryMovePiece();

	//"����" ������ "������" �� �����
	void buildPieceMoveTypes(std::unordered_map<PieceList, std::vector<MoveType>>& mp);

	// ������ ��� ������ ������ �� ����� ��������� ����������� ���������
	void placeStarterPieceOnDesk(std::unordered_map<std::string, Piece*>& mp);
};

