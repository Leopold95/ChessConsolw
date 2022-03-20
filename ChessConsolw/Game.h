#pragma once

#include "Utils.hpp"
#include "Desk.h"
#include "SystemVariables.h"

class Game
{
public:
	void startNewGame();
	void endCurrentGame();

	~Game();

private:
	Desk* desk = new Desk();
};

