#include "CommandRemouter.h"

void CommandRemouter::onNewCommand(short c)
{
	switch (c)
	{
	case 8:
		break;

	default:
		std::cout << "Ta��� ������ �� ���������." << std::endl;
		std::cout << "�� �������: " << c << std::endl;
		break;
	}
}

void CommandRemouter::onNewCommand(std::string c)
{
	std::cout << c << std::endl;
}

void CommandRemouter::onNewCommandArgs(vecstr& args)
{
	if (boost::algorithm::iequals(args[0], "move"))
	{
		string firstPos = args[1];
		string secondPos = args[2];


		
	}
}

void CommandRemouter::clearConsole()
{
	std::system("CLS");
}

void CommandRemouter::printCommands()
{
	print("�� ������ � ��������. ������� �� �������. ��");
	print("0 - ��� ������ �����");
	print("1 - �������");
	print("");
	print("");
	print("");
	print("");
	print("");
	print("");
	print("");
	print("");
	print("");
	print("");
	print("");
}

void CommandRemouter::print(string s)
{
	std::cout << s << std::endl;
}

void CommandRemouter::printPiece(PieceList p)
{
	std::cout << (char)p << std::endl;
}



void CommandRemouter::printRules()
{
	print("������� ���:");
	print("move <��������� ������� ������> <��������� ��������� ������>");
	print("��������� ��������� � ������� �-1, �-6....");
}
