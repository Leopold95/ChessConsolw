#pragma once

#include <iostream>
#include <memory>

#include "Utils.hpp"
#include "Desk.h"

class Game
{
public:
	void startNewGame();
	void endCurrentGame();

	~Game();

private:
	Desk* desk = new Desk();
};

