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
	sound.setVolume(sv->SoundOptions.SoundsVolume);
	sound.play();
}

void GameSound::play(sf::Sound& sound, short volume)
{
	sound.setVolume(volume);
	sound.play();
	sound.setVolume(sv->SoundOptions.SoundsVolume);
}

GameSound::GameSound()
{
	initMusic();
	_currentBacgroundMusic = new sf::Music();

	buffer_movePiece.loadFromFile(soundList.pieceMove);
	sound_movePiece.setBuffer(buffer_movePiece);

	buffer_gameStart.loadFromFile(soundList.music_gameStart);
	sound_gameStart.setBuffer(buffer_gameStart);

	musicProcessor = spawnThread();
}

void GameSound::initMusic()
{
	for (auto& item : soundList.backMusic)
	{
		//backgroundMusicList.add(new sf::Music());
	}
}

void GameSound::bacgroundMusicProcessor()
{
	while (true)
	{ 
		//TODO make normal backgorund check system
		if (_currentBacgroundMusic->getStatus() == sf::Music::Stopped)
		{
			short randomId = sv->randomShort(0, backgroundMusicList.size());

			_currentBacgroundMusic = nullptr;

			_currentBacgroundMusic = backgroundMusicList.getId(randomId);
			_currentBacgroundMusic->play();
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(2000));	
	}
}

std::thread GameSound::spawnThread()
{
	return std::thread([this] { this->bacgroundMusicProcessor(); });
}
