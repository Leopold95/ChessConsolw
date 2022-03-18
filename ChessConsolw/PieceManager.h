#pragma once

#include <unordered_map>
#include <string>
#include <vector>

#include "MoveType.hpp"
#include "Pieces.hpp"
#include "Utils.hpp"

class PieceManager
{
public:
	void tryMovePiece();

	//"����" ������ "������" �� �����
	void buildPieceMoveTypes(std::unordered_map<PieceList, std::vector<MoveType>>& mp);

	// ������ ��� ������ ������ �� ����� ��������� ����������� ���������
	void placeStarterPieceOnDesk(std::unordered_map<std::string, Piece*>& mp);

private:
};

