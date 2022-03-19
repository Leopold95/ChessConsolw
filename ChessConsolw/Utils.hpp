#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>

#include "Pieces.hpp"

#include "MoveType.hpp"

#include "SystemVariables.h"


using vecstr = std::vector<std::string>;
using std::string;
using std::cin;
using std::cout;

class Utils
{
private:
	//SystemVariables& sv = SystemVariables::GetInstanse();

public:
	//получить 50 рандомных буквенных символов в строке нижнего и верхнего регистра
	static std::string getRandomStr()
	{
		char letters[] = "abcdefghijklmnopqrstuvwxyz";
		char upperLetters[] = "QWERTYUIOPASDFGHJKLZXCVBNM";

		std::string s = "";

		for (size_t i = 0; i < 50; i++)
		{
			short b = 0 + rand() % 2;

			if (b == 0)
			{
				s.push_back(letters[rand() % 26]);
			}
			else
			{
				s.push_back(upperLetters[rand() % 26]);
			}
		}

		return s;
	}

	//разделить строку str на строки и записать в вектор. Разделяющий символ 'с'
	static void split(vecstr& cont, const char* str, const char& c)
	{
		//код спизжен и не изетсно как работает но работает
		do
		{
			const char* begin = str;

			while (*str != c && *str)
				str++;

			cont.push_back(string(begin, str));
		} while (0 != *str++);
	}

	template<typename T>
	static inline void println(T s)
	{
		std::cout << s << std::endl;
	}

	//считать стороку с аргументами с косоли
	static string getConsoleString()
	{
		std::string n = "";
		std::getline(std::cin, n);

		return n;
	}

	//получить map piecelist enum и символ фигуры к нему
	static void getPieceSymbolMap(std::unordered_map<PieceList, char>& map)
	{
		map.insert(std::make_pair(PieceList::Bishop, 'b'));
		map.insert(std::make_pair(PieceList::King, 'K'));
		map.insert(std::make_pair(PieceList::Knight, 'k'));
		map.insert(std::make_pair(PieceList::Pawn, 'p'));
		map.insert(std::make_pair(PieceList::Queen, 'Q'));
		map.insert(std::make_pair(PieceList::Rook, 'r'));
	}

	static void deletePiecesInMap(std::unordered_map<std::string, Piece*>& mp)
	{
		for (auto& item : mp)
		{
			delete item.second;
		}
	}

	static void deletePiece(Piece* piece)
	{
		delete piece;
	}

	//возвращает 1-8 из A-B
	static int makeNumberFromStringPosition(string& location)
	{
		if (location.compare("A") == 0) return 1;
		else if (location.compare("B") == 0) return 2;
		else if (location.compare("C") == 0) return 3;
		else if (location.compare("D") == 0) return 4;
		else if (location.compare("E") == 0) return 5;
		else if (location.compare("F") == 0) return 6;
		else if (location.compare("G") == 0) return 7;
		else if (location.compare("H") == 0) return 8;
		else return 0;
	}
};