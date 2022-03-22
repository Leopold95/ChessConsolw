#include "CommandRemouter.h"

void CommandRemouter::onNewCommand(short c)
{
	switch (c)
	{
	case 8:
		break;

	default:
		std::cout << "Taкой комнды не сущесвует." << std::endl;
		std::cout << "Вы ввыелии: " << c << std::endl;
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
	print("Вы попали в хуяхматы. Удалите их обратно. пж");
	print("0 - ход пешкой вверх");
	print("1 - Правила");
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
	print("Сделать ход:");
	print("move <положение союзной фигуры> <положение вражеской фигуры>");
	print("положения указывать в формате А-1, Г-6....");
}
