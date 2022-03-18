#pragma once

#include <vector>
#include <string>
#include <list>
#include <iostream>
#include <unordered_map>

#include "Piece.hpp"
#include "PieceList.hpp"
#include "MoveType.hpp"

#include "Location.hpp"
#include "SystemVariables.h"

#include "Pawn.hpp"
#include "King.hpp"
#include "Queen.hpp"
#include "Rook.hpp"
#include "Knight.hpp"
#include "Bishop.hpp"

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

	//задать для каждой фигуры на доске начальное стандартное положение
	static void initialiseDefaulPieceOnDeskMap(std::unordered_map<std::string, Piece*>& mp)
	{
		mp.emplace(getRandomStr(), new Pawn(PieceList::Pawn, Color::White, Location(1, 7)));
		mp.emplace(getRandomStr(), new Pawn(PieceList::Pawn, Color::White, Location(2, 7)));
		mp.emplace(getRandomStr(), new Pawn(PieceList::Pawn, Color::White, Location(3, 7)));
		mp.emplace(getRandomStr(), new Pawn(PieceList::Pawn, Color::White, Location(4, 7)));
		mp.emplace(getRandomStr(), new Pawn(PieceList::Pawn, Color::White, Location(5, 7)));
		mp.emplace(getRandomStr(), new Pawn(PieceList::Pawn, Color::White, Location(6, 7)));
		mp.emplace(getRandomStr(), new Pawn(PieceList::Pawn, Color::White, Location(7, 7)));
		mp.emplace(getRandomStr(), new Pawn(PieceList::Pawn, Color::White, Location(8, 7)));

		mp.emplace(getRandomStr(), new Rook(PieceList::Rook, Color::White, Location(1, 8)));
		mp.emplace(getRandomStr(), new Knight(PieceList::Knight, Color::White, Location(2, 8)));
		mp.emplace(getRandomStr(), new Bishop(PieceList::Bishop, Color::White, Location(3, 8)));
		mp.emplace(getRandomStr(), new King(PieceList::King, Color::White, Location(4, 8)));
		mp.emplace(getRandomStr(), new Queen(PieceList::Queen, Color::White, Location(5, 8)));
		mp.emplace(getRandomStr(), new Bishop(PieceList::Bishop, Color::White, Location(6, 8)));
		mp.emplace(getRandomStr(), new Knight(PieceList::Knight, Color::White, Location(7, 8)));
		mp.emplace(getRandomStr(), new Rook(PieceList::Rook, Color::White, Location(8, 8)));


		mp.emplace(getRandomStr(), new Pawn(PieceList::Pawn, Color::Black, Location(1, 2)));
		mp.emplace(getRandomStr(), new Pawn(PieceList::Pawn, Color::Black, Location(2, 2)));
		mp.emplace(getRandomStr(), new Pawn(PieceList::Pawn, Color::Black, Location(3, 2)));
		mp.emplace(getRandomStr(), new Pawn(PieceList::Pawn, Color::Black, Location(4, 2)));
		mp.emplace(getRandomStr(), new Pawn(PieceList::Pawn, Color::Black, Location(5, 2)));
		mp.emplace(getRandomStr(), new Pawn(PieceList::Pawn, Color::Black, Location(6, 2)));
		mp.emplace(getRandomStr(), new Pawn(PieceList::Pawn, Color::Black, Location(7, 2)));
		mp.emplace(getRandomStr(), new Pawn(PieceList::Pawn, Color::Black, Location(8, 2)));

		mp.emplace(getRandomStr(), new Rook(PieceList::Rook, Color::Black, Location(1, 1)));
		mp.emplace(getRandomStr(), new Knight(PieceList::Knight, Color::Black, Location(2, 1)));
		mp.emplace(getRandomStr(), new Bishop(PieceList::Bishop, Color::Black, Location(3, 1)));
		mp.emplace(getRandomStr(), new King(PieceList::King, Color::Black, Location(4, 1)));
		mp.emplace(getRandomStr(), new Queen(PieceList::Queen, Color::Black, Location(5, 1)));
		mp.emplace(getRandomStr(), new Bishop(PieceList::Bishop, Color::Black, Location(6, 1)));
		mp.emplace(getRandomStr(), new Knight(PieceList::Knight, Color::Black, Location(7, 1)));
		mp.emplace(getRandomStr(), new Rook(PieceList::Rook, Color::Black, Location(8, 1)));
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

	//"учит" фигуру "ходить" на доске
	static void initialisePieceMoveTypes(std::unordered_map<PieceList, std::vector<MoveType>>& mp)
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
};