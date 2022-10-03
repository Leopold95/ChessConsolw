#pragma once

#include <SFML/Audio.hpp>
#include <string>
#include <thread>
#include <chrono>
#include <random>

#include "Structs.hpp"
#include "SystemVariables.h"
#include "IterableVector.hpp"

class GameSound
{
public:
	~GameSound();
	static GameSound* Instanse();

	sf::Sound sound_movePiece;
	sf::Sound sound_enemyPieceDeath;

private:
	GameSound();
	GameSound(GameSound&) = delete;
	void operator=(const GameSound&) = delete;
	GameSound& operator=(GameSound&) = delete;
	static GameSound* _instanse;

	void initMusic();

	void bacgroundMusicProcessor() noexcept;
	std::thread spawnThread();
	std::thread musicProcessor;

	SystemVariables* sv = SystemVariables::GetInstanse();

	Structs::SoundList soundList;

	sf::SoundBuffer buffer_movePiece;
	sf::SoundBuffer buffer_enemyPieceDeath;

	sf::Music* _currentBacgroundMusic;

	IterableVector<sf::Music*> backgroundMusicList;
};

