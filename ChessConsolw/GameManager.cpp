#include "GameManager.h"

void GameManager::movePiece(string firstPos, string secondPos)
{
	//проверить что оба положения верны и валидны

	//for (const auto& i : sv.getAllPositionList())
	//{
	//	if (boost::iequals(firstPos, i)) //проверка игнорируя регистры(большая/малькая буквы)
	//	{
	//		//print(firstPos);
	//	}
	//}
	//for (const auto& i : sv.getAllPositionList())
	//{
	//	if (boost::iequals(firstPos, i))
	//	{
	//		//print(secondPos);
	//	}
	//}

	//провреить что на первом положении етсь союзная фигура
	//for (const auto& i : sv.getPiecesOnDeskMap())
	//{
	//	string location =
	//		Utils::locationLetterToString(i.second->CurrentLocation().LocLetter())
	//		+ "-" +
	//		Utils::locationNumberToString(i.second->CurrentLocation().LocNumber());


	//	if (i.second->CurrentColor() == Color::White)
	//	{
	//		if (firstPos == location)
	//		{
	//			//print("есть фигура в первом положении");
	//		}
	//		else
	//		{
	//			//print("в первом положении нет вражеской фигуры");
	//		}
	//	}
	//}

	//провреить что на втором положении етсь вражеская фигура
	//for (const auto& i : sv.getPiecesOnDeskMap())
	//{
	//	string location =
	//		Utils::locationLetterToString(i.second->CurrentLocation().LocLetter())
	//		+ "-" +
	//		Utils::locationNumberToString(i.second->CurrentLocation().LocNumber());

	//	if (i.second->CurrentColor() == Color::Black)
	//	{
	//		if (secondPos == location)
	//		{
	//			//print("есть фигура во втором положении");
	//		}
	//		else
	//		{
	//			//print("во втором положении нет союзной фигуры");
	//		}
	//	}
	//}

	//соврешить изменение союзной фигуры в соотвецтвии с *правилами хождения фигур*
	//провреить что новое положение союзной фигуры не совпадает с положением вражеской
}

void GameManager::movePiece(Location& firstPos, Location& secondPos)
{
	//проверить что оба положения верны и валидны
	if (firstPos.x < 1 && firstPos.x > 9 && firstPos.y < 1 && firstPos.y > 9)
	{
		//первое положение валидно
	}
	else throw new std::exception("Первое положение не валидное");

	if (secondPos.x < 1 && secondPos.x > 9 && secondPos.y < 1 && secondPos.y > 9)
	{
		//второе положение валидно
	}
	else throw new std::exception("Второе положение не валидное");

	//провреить что на первом положении етсь союзная фигура
	//for (const auto& i : sv.getPiecesOnDeskMap())
	//{
	//	if (i.second->CurrentColor() == Color::White)
	//	{
	//		if (i.second->CurrentLocation() == firstPos)
	//		{
	//			//есть союзная фигура в первом положении
	//		}
	//		else
	//		{
	//			//нету союзной фигура в первом положении
	//		}
	//	}
	//}

	//провреить что на втором положении етсь вражеская фигура
	//for (const auto& i : sv.getPiecesOnDeskMap())
	//{
	//	if (i.second->CurrentColor() == Color::Black)
	//	{
	//		if (i.second->CurrentLocation() == secondPos)
	//		{
	//			//есть вражеская фигура во втором положении
	//		}
	//		else
	//		{
	//			//нету вражекой фигуры во втором положении
	//		}
	//	}
	//}

	//соврешить изменение союзной фигуры в соотвецтвии с *правилами хождения фигур*
	//Location tempLoc;
	//Piece* p = Utils::getPieceFromLocation(firstPos);

	//switch (p->CurrentPiece())
	//{
	//case PieceList::Bishop:
	//	tempLoc.x = firstPos.x;
	//	tempLoc.y = firstPos.y;

	//	break;

	//case PieceList::King: {
	//	int temp1 = firstPos.x - secondPos.x;
	//	int temp2 = firstPos.y - secondPos.y;

	//	if (temp1 == std::clamp(temp1, 1, 2))
	//	{

	//	}
	//	else throw new std::exception("fist pos is not valid for move king");

	//	if (temp2 == std::clamp(temp2, 1, 2))
	//	{

	//	}
	//	else throw new std::exception("fist pos is not valid for move king");
	//	break;
	//}
	//case PieceList::Knight:
	//	break;

	//case PieceList::Pawn: {
	//	int temp1 = firstPos.x - secondPos.x;
	//	int tamp2 = firstPos.y - secondPos.y;

	//	if (temp1 == std::clamp(temp1, 1, 2))
	//	{

	//	}
	//	else throw new std::exception("fist pos is not valid for move pawn");
	//	break; 
	//}

	//case PieceList::Queen:
	//	break;

	//case PieceList::Rook:
	//	break;

	//default:
	//	break;
	//}

	//delete p;
	//p = nullptr;
	//провреить что новое положение союзной фигуры не совпадает с положением вражеской
}
