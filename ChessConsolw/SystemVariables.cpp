#include "SystemVariables.h"

SystemVariables SystemVariables::instanse;
PieceManager SystemVariables::_pieceManger;

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


SystemVariables::SystemVariables() 
{ 
	//_pieceManger.placeStarterPieceOnDesk(piecesOnDeskMap);
	//_pieceManger.buildPieceMoveTypes(pieceMoveTypes);
}