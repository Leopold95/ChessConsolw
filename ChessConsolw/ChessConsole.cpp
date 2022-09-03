#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <thread>

#include "SoundSystem.h"
#include <SFML/Audio.hpp>

#include "SystemVariables.h"
#include "CommandRemouter.h"
#include "Desk.h"
#include "Utils.hpp"
#include "Game.h"

#include <Windows.h>

using std::string;
using std::vector;

using vecstr = std::vector<std::string>;

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


int main(int argc, char* argv[])
{
	argumentChecker(argc, argv);

	SetConsoleTitleA("Chess Game");
	std::setlocale(LC_ALL, "Ru");
	std::time_t t;
	std::srand((unsigned int)std::time(&t));

	SystemVariables& sv = SystemVariables::GetInstanse();
	
	Game* game = new Game();

	SoundSystem* ss = new SoundSystem();
	ss->play("Assets/Sounds/piecemoved.wav");



	std::cin.get();


	//game->startNewGame();



	//Client client("127.0.0.1", 25535);
	//client.Connect();


	delete game;
	return 0;
}
