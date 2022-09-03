#pragma once 

#include "Logger.hpp"

#include <SFML/Audio.hpp>
#include <string>
#include <exception>


class SoundManager
{
public:
	void play(std::string);

private:
	Logger _logger;
};


void SoundManager::play(std::string name)
{
	sf::SoundBuffer _buffer;
	try
	{
		bool sucsess = _buffer.loadFromFile(name);

		sf::Sound sound(_buffer);
		sound.play();
	}
	catch (std::exception& ex)
	{
		_logger.WriteFile("Cant paly sound. SoundManager.hpp play()"
			+ std::string(ex.what()));
	}
}
