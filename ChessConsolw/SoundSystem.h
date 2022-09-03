#pragma once

#include <string>
#include <SFML/Audio.hpp>
#include "Logger.hpp"

class SoundSystem
{
public:
	void play(std::string);

private:
	Logger _logger;
	sf::SoundBuffer buffer;
	sf::Sound sound;
};

