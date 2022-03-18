#include "SystemVariables.h"

SystemVariables SystemVariables::instanse;

SystemVariables& SystemVariables::GetInstanse()
{
	return instanse;
}

std::unordered_map<std::string, Piece*>& SystemVariables::getPiecesOnDeskMap()
{
	return piecesOnDeskMap;
}

std::unordered_map<PieceList, std::vector<MoveType>>& SystemVariables::getPieceMoveTypes()
{
	return pieceMoveTypes;
}

void SystemVariables::initialise()
{
	Utils::initialiseDefaulPieceOnDeskMap(piecesOnDeskMap);
	Utils::initialisePieceMoveTypes(pieceMoveTypes);
}

SystemVariables::SystemVariables() { initialise(); }