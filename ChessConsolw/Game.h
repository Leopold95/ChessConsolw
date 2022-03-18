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

private:
	std::unique_ptr<Desk> desk = std::make_unique<Desk>(new Desk);
};

