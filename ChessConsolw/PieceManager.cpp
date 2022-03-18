#include "PieceManager.h"

void PieceManager::tryMovePiece()
{
}

void PieceManager::buildPieceMoveTypes(std::unordered_map<PieceList, std::vector<MoveType>>& mp)
{
	std::vector<MoveType> pawnMoveTypes;
	pawnMoveTypes.push_back(MoveType::Forword);
	pawnMoveTypes.push_back(MoveType::Dioganally);
	mp.emplace(PieceList::Bishop, pawnMoveTypes);

	std::vector<MoveType> kingMoveTypes;
	kingMoveTypes.push_back(MoveType::OneStep);
	kingMoveTypes.push_back(MoveType::OneStepDioganally);
	kingMoveTypes.push_back(MoveType::BackwordOneStep);
	kingMoveTypes.push_back(MoveType::BackwordOneStepDioganally);
	mp.emplace(PieceList::King, kingMoveTypes);

	std::vector<MoveType> queenMoveTypes;
	queenMoveTypes.push_back(MoveType::Forword);
	queenMoveTypes.push_back(MoveType::Dioganally);
	queenMoveTypes.push_back(MoveType::Backword);
	queenMoveTypes.push_back(MoveType::BackwordDiogannaly);
	mp.emplace(PieceList::Queen, queenMoveTypes);

	std::vector<MoveType> rookMoveTypes;
	rookMoveTypes.push_back(MoveType::Forword);
	rookMoveTypes.push_back(MoveType::Backword);
	rookMoveTypes.push_back(MoveType::Right);
	rookMoveTypes.push_back(MoveType::Left);
	mp.emplace(PieceList::Rook, rookMoveTypes);

	std::vector<MoveType> knightMoveTyps;
	knightMoveTyps.push_back(MoveType::Dioganally);
	kingMoveTypes.push_back(MoveType::BackwordDiogannaly);
	mp.emplace(PieceList::Knight, knightMoveTyps);

	std::vector<MoveType> bishopMoveTypes;
	bishopMoveTypes.push_back(MoveType::Bishop);
	mp.emplace(PieceList::Bishop, bishopMoveTypes);
}

void PieceManager::placeStarterPieceOnDesk(std::unordered_map<std::string, Piece*>& mp)
{
	mp.emplace(Utils::getRandomStr(), new Pawn(PieceList::Pawn, Color::White, Location(1, 7)));
	mp.emplace(Utils::getRandomStr(), new Pawn(PieceList::Pawn, Color::White, Location(2, 7)));
	mp.emplace(Utils::getRandomStr(), new Pawn(PieceList::Pawn, Color::White, Location(3, 7)));
	mp.emplace(Utils::getRandomStr(), new Pawn(PieceList::Pawn, Color::White, Location(4, 7)));
	mp.emplace(Utils::getRandomStr(), new Pawn(PieceList::Pawn, Color::White, Location(5, 7)));
	mp.emplace(Utils::getRandomStr(), new Pawn(PieceList::Pawn, Color::White, Location(6, 7)));
	mp.emplace(Utils::getRandomStr(), new Pawn(PieceList::Pawn, Color::White, Location(7, 7)));
	mp.emplace(Utils::getRandomStr(), new Pawn(PieceList::Pawn, Color::White, Location(8, 7)));

	mp.emplace(Utils::getRandomStr(), new Rook(PieceList::Rook, Color::White, Location(1, 8)));
	mp.emplace(Utils::getRandomStr(), new Knight(PieceList::Knight, Color::White, Location(2, 8)));
	mp.emplace(Utils::getRandomStr(), new Bishop(PieceList::Bishop, Color::White, Location(3, 8)));
	mp.emplace(Utils::getRandomStr(), new King(PieceList::King, Color::White, Location(4, 8)));
	mp.emplace(Utils::getRandomStr(), new Queen(PieceList::Queen, Color::White, Location(5, 8)));
	mp.emplace(Utils::getRandomStr(), new Bishop(PieceList::Bishop, Color::White, Location(6, 8)));
	mp.emplace(Utils::getRandomStr(), new Knight(PieceList::Knight, Color::White, Location(7, 8)));
	mp.emplace(Utils::getRandomStr(), new Rook(PieceList::Rook, Color::White, Location(8, 8)));


	mp.emplace(Utils::getRandomStr(), new Pawn(PieceList::Pawn, Color::Black, Location(1, 2)));
	mp.emplace(Utils::getRandomStr(), new Pawn(PieceList::Pawn, Color::Black, Location(2, 2)));
	mp.emplace(Utils::getRandomStr(), new Pawn(PieceList::Pawn, Color::Black, Location(3, 2)));
	mp.emplace(Utils::getRandomStr(), new Pawn(PieceList::Pawn, Color::Black, Location(4, 2)));
	mp.emplace(Utils::getRandomStr(), new Pawn(PieceList::Pawn, Color::Black, Location(5, 2)));
	mp.emplace(Utils::getRandomStr(), new Pawn(PieceList::Pawn, Color::Black, Location(6, 2)));
	mp.emplace(Utils::getRandomStr(), new Pawn(PieceList::Pawn, Color::Black, Location(7, 2)));
	mp.emplace(Utils::getRandomStr(), new Pawn(PieceList::Pawn, Color::Black, Location(8, 2)));

	mp.emplace(Utils::getRandomStr(), new Rook(PieceList::Rook, Color::Black, Location(1, 1)));
	mp.emplace(Utils::getRandomStr(), new Knight(PieceList::Knight, Color::Black, Location(2, 1)));
	mp.emplace(Utils::getRandomStr(), new Bishop(PieceList::Bishop, Color::Black, Location(3, 1)));
	mp.emplace(Utils::getRandomStr(), new King(PieceList::King, Color::Black, Location(4, 1)));
	mp.emplace(Utils::getRandomStr(), new Queen(PieceList::Queen, Color::Black, Location(5, 1)));
	mp.emplace(Utils::getRandomStr(), new Bishop(PieceList::Bishop, Color::Black, Location(6, 1)));
	mp.emplace(Utils::getRandomStr(), new Knight(PieceList::Knight, Color::Black, Location(7, 1)));
	mp.emplace(Utils::getRandomStr(), new Rook(PieceList::Rook, Color::Black, Location(8, 1)));
}
