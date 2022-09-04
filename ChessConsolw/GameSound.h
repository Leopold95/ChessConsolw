#pragma once

#include <SFML/Audio.hpp>
#include <string>

#include "SoundList.hpp"

class GameSound
{
public:
	static GameSound* Instanse();

	void play(std::string);
	void play(std::string, short);
	void play(sf::Sound&);
	void play(sf::Sound&, short);

	sf::Sound sound_movePiece;
	sf::Sound sound_gameStart;

private:
	GameSound();
	GameSound(GameSound& other) = delete;
	void operator=(const GameSound&) = delete;
	GameSound& operator=(GameSound&) = delete;
	static GameSound* _instanse;

	short _defaultVolume = 40;

	SoundList soundList;

	sf::SoundBuffer buffer_movePiece;
	sf::SoundBuffer buffer_gameStart;
};

