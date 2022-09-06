#include "GameSound.h"

GameSound* GameSound::_instanse;

GameSound* GameSound::Instanse()
{
	if (_instanse == nullptr)
		_instanse = new GameSound();

	return _instanse;
}

void GameSound::play(sf::Sound& sound)
{
	sound.setVolume(_defaultSoundVolume);
	sound.play();
}

void GameSound::play(sf::Sound& sound, short volume)
{
	sound.setVolume(volume);
	sound.play();
	sound.setVolume(_defaultSoundVolume);
}

GameSound::GameSound()
{
	initMusic();

	buffer_movePiece.loadFromFile(soundList.pieceMove);
	sound_movePiece.setBuffer(buffer_movePiece);

	buffer_gameStart.loadFromFile(soundList.gameStart);
	sound_gameStart.setBuffer(buffer_gameStart);

	musicProcessor = spawnThread();

	_backgroundMusicList.push_back(music_background_1);
}

void GameSound::initMusic()
{
	music_background_1 = new sf::Music();
	music_background_1->openFromFile(soundList.music_backGround);
	music_background_1->setVolume(_defaultMusicVolume);
}

void GameSound::bacgroundMusicProcessor()
{
	while (true)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(2000));

		if (_currentBackgroundMusic == nullptr)
		{
			_currentBackgroundMusic = _backgroundMusicList[std::rand() % _backgroundMusicList.size()];
		}
		else if(_currentBackgroundMusic != nullptr && _currentBackgroundMusic->Playing)
		{
			continue;
		}
		else
		{
			_currentBackgroundMusic->play();
		}
	}
}

std::thread GameSound::spawnThread()
{
	return std::thread([this] { this->bacgroundMusicProcessor(); });
}
