#include "Console.h"

std::vector<std::string> ConsolePromoute::Console::getConsoleArgs()
{
	const char* str;
	std::string n = "";
	std::getline(std::cin, n);
	str = n.c_str();

	std::vector<std::string> args;

	//not own-writed code
	do
	{
		const char* begin = str;

		while (*str != ' ' && *str)
			str++;

		args.push_back(std::string(begin, str));
	} while (0 != *str++);

	return args;
}

//void ConsolePromoute::Console::printDesk(Desk& desk)
//{
//	for (const auto& [id, piece] : desk.Pieces)
//	{
//		if (piece->CurrentColor() == Color::White)
//		{
//			serCursorPos(piece->CurrentLocation().x, piece->CurrentLocation().x);
//			printWhite(_gameLogic.pieceTypeToStr(piece->CurrentPiece()));
//			continue;
//		}
//
//		if (piece->CurrentColor() == Color::Black)
//		{
//			serCursorPos(piece->CurrentLocation().x, piece->CurrentLocation().x);
//			printBlack(_gameLogic.pieceTypeToStr(piece->CurrentPiece()));
//			continue;
//		}
//	}
//}

void ConsolePromoute::Console::serCursorPos(int x, int y)
{
	printf("%c[%d;%df", 0x1B, y, x);
}

void ConsolePromoute::Console::printWhite(char piece)
{
	printf("\033[38;5;%dm %c\033[m", 15, piece);
}

void ConsolePromoute::Console::printBlack(char piece)
{
	printf("\033[38;5;%dm %c\033[m", 27, piece);
}
