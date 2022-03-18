#pragma once

#include <vector>
#include <string>
#include <unordered_map>

#include "PieceManager.h"
#include "Piece.hpp"
#include "MoveType.hpp"

//must be initialised before using variables


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
	PieceManager _pieceManger;

	//������� ��������� � ������ ���������� ������ ������ �� �����
	//� ������ ���������� ���������� �� ��� ������ ������
	std::unordered_map<std::string, Piece*> piecesOnDeskMap;

	//������� ������ � �� ����� ��������
	std::unordered_map<PieceList, std::vector<MoveType>> pieceMoveTypes;
};