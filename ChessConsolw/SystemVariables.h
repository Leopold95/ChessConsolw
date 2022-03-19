#pragma once

#include <vector>
#include <string>
#include <unordered_map>

#include "PieceManager.h"
#include "MoveType.hpp"

class SystemVariables
{
public:
	static SystemVariables& GetInstanse();
	SystemVariables(const SystemVariables&) = delete;

	//std::vector<std::string>& getAllPositionList();
	std::unordered_map<std::string, Piece*>& getPiecesOnDeskMap();
	std::unordered_map<PieceList, std::vector<MoveType>>& getPieceMoveTypes();

private:
	SystemVariables();
	static SystemVariables instanse;
	static PieceManager _pieceManger;

	//������� ��������� � ������ ���������� ������ ������ �� �����
	//� ������ ���������� ���������� �� ��� ������ ������
	std::unordered_map<std::string, Piece*> piecesOnDeskMap;

	//������� ������ � �� ����� ��������
	std::unordered_map<PieceList, std::vector<MoveType>> pieceMoveTypes;
};