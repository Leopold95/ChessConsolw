#pragma once

#include <SFML/Audio.hpp>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include <random>

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

	void initMusic();

	void bacgroundMusicProcessor();
	std::thread spawnThread();
	std::thread musicProcessor;

	short _defaultSoundVolume = 40;
	short _defaultMusicVolume = 10;

	SoundList soundList;
	sf::SoundBuffer buffer_movePiece;
	sf::SoundBuffer buffer_gameStart;

	sf::Music* _currentBackgroundMusic;

	sf::Music* music_background_1;

	std::vector<sf::Music*> _backgroundMusicList;
};

