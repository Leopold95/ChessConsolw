#pragma once

#include <vector>
#include <string>
#include <unordered_map>

#include "Utils.hpp"
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

	void initialise(); //needs for initialise all variables - called automatically when class constructor were called

	//������� ��������� � ������ ���������� ������ ������ �� �����
	//� ������ ���������� ���������� �� ��� ������ ������
	std::unordered_map<std::string, Piece*> piecesOnDeskMap;

	//������� ������ � �� ����� ��������
	std::unordered_map<PieceList, std::vector<MoveType>> pieceMoveTypes;
};