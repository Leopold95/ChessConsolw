#include "GameManager.h"

void GameManager::movePiece(string firstPos, string secondPos)
{
	//��������� ��� ��� ��������� ����� � �������

	//for (const auto& i : sv.getAllPositionList())
	//{
	//	if (boost::iequals(firstPos, i)) //�������� ��������� ��������(�������/������� �����)
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

	//��������� ��� �� ������ ��������� ���� ������� ������
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
	//			//print("���� ������ � ������ ���������");
	//		}
	//		else
	//		{
	//			//print("� ������ ��������� ��� ��������� ������");
	//		}
	//	}
	//}

	//��������� ��� �� ������ ��������� ���� ��������� ������
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
	//			//print("���� ������ �� ������ ���������");
	//		}
	//		else
	//		{
	//			//print("�� ������ ��������� ��� ������� ������");
	//		}
	//	}
	//}

	//��������� ��������� ������� ������ � ����������� � *��������� �������� �����*
	//��������� ��� ����� ��������� ������� ������ �� ��������� � ���������� ���������
}

void GameManager::movePiece(Location& firstPos, Location& secondPos)
{
	//��������� ��� ��� ��������� ����� � �������
	if (firstPos.x < 1 && firstPos.x > 9 && firstPos.y < 1 && firstPos.y > 9)
	{
		//������ ��������� �������
	}
	else throw new std::exception("������ ��������� �� ��������");

	if (secondPos.x < 1 && secondPos.x > 9 && secondPos.y < 1 && secondPos.y > 9)
	{
		//������ ��������� �������
	}
	else throw new std::exception("������ ��������� �� ��������");

	//��������� ��� �� ������ ��������� ���� ������� ������
	//for (const auto& i : sv.getPiecesOnDeskMap())
	//{
	//	if (i.second->CurrentColor() == Color::White)
	//	{
	//		if (i.second->CurrentLocation() == firstPos)
	//		{
	//			//���� ������� ������ � ������ ���������
	//		}
	//		else
	//		{
	//			//���� ������� ������ � ������ ���������
	//		}
	//	}
	//}

	//��������� ��� �� ������ ��������� ���� ��������� ������
	//for (const auto& i : sv.getPiecesOnDeskMap())
	//{
	//	if (i.second->CurrentColor() == Color::Black)
	//	{
	//		if (i.second->CurrentLocation() == secondPos)
	//		{
	//			//���� ��������� ������ �� ������ ���������
	//		}
	//		else
	//		{
	//			//���� �������� ������ �� ������ ���������
	//		}
	//	}
	//}

	//��������� ��������� ������� ������ � ����������� � *��������� �������� �����*
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
	//��������� ��� ����� ��������� ������� ������ �� ��������� � ���������� ���������
}
