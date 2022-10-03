#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <random>

#include "SystemVariables.h"
#include "GameSound.h"
#include "Game.h"

#include <Windows.h>

using std::string;
using std::cin;
using std::cout;
using std::endl;


//COLORPRIORITY(WHITE, BLACK, NONE) default NONE
//DIFFICULT(EASY, MEDIUM, HARD) default EASY

//SERVER(IP)
//SERVER(PORT)

void argumentChecker(int c, char* args[])
{
	if (c <= 0)
	{
		exit(3);
	}

	

	if (args[0] == "")
	{
		exit(3);
	}
	else
	{
		if (args[1])
		{

		}
	}
	 
}

void printWhite(std::string piece)
{
	printf("\033[38;5;%dm %s\033[m", 15, piece.c_str());
}

void printBlack(std::string piece)
{
	printf("\033[38;5;%dm %s\033[m", 27, piece.c_str());
}



int main(int argc, char* argv[])
{
	argumentChecker(argc, argv);

	SetConsoleTitleA("Chess Game");
	std::setlocale(LC_ALL, "Ru");
	std::time_t t;
	std::srand((unsigned int)std::time(&t));

	SystemVariables* sv = SystemVariables::GetInstanse();
	GameSound* gameSound = GameSound::Instanse();

	Game* game = new Game();
	game->startNewGame();

	printBlack("d");
	printWhite("p");


	//Client client("127.0.0.1", 25535);
	//client.Connect();


	std::cin;
	delete gameSound;
	delete game;
	delete sv;
	return 0;
}
