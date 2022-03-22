#pragma once
#ifndef _UTILS_HPP_
#define _UTILS_HPP_

#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>

#include "Pieces.hpp"
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
};

#endif