#pragma once

#include <SFML/Audio.hpp>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include <random>

#include "Structs.hpp"
#include "SystemVariables.h"
#include "IterableVector.h"

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
	GameSound(GameSound&) = delete;
	void operator=(const GameSound&) = delete;
	GameSound& operator=(GameSound&) = delete;
	static GameSound* _instanse;

	void initMusic();

	void bacgroundMusicProcessor();
	std::thread spawnThread();
	std::thread musicProcessor;

	SystemVariables* sv = SystemVariables::GetInstanse();

	Structs::SoundList soundList;
	sf::SoundBuffer buffer_movePiece;
	sf::SoundBuffer buffer_gameStart;

	sf::Music* _currentBacgroundMusic;

	IterableVector<sf::Music*> backgroundMusicList;
};

