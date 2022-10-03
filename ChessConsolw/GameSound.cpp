#include "GameSound.h"

GameSound* GameSound::_instanse;

GameSound::~GameSound()
{
	for (size_t i = 0; i < soundList.backMusic.size(); i++)
		delete backgroundMusicList.getId(i);
}

GameSound* GameSound::Instanse()
{
	if (_instanse == nullptr)
		_instanse = new GameSound();

	return _instanse;
}

GameSound::GameSound()
{
	initMusic();
	_currentBacgroundMusic = new sf::Music();

	musicProcessor = spawnThread();
}

void GameSound::initMusic()
{
	buffer_movePiece.loadFromFile(soundList.pieceMove);
	sound_movePiece.setBuffer(buffer_movePiece);
	sound_movePiece.setVolume(80);

	buffer_enemyPieceDeath.loadFromFile(soundList.sound_EnemyPieceDeath);
	sound_enemyPieceDeath.setBuffer(buffer_enemyPieceDeath);

	//!!!два цикла необходимы!!!

	//заполнение списка музыки пустыми треками
	for (size_t i = 0; i < soundList.backMusic.size(); i++)
		backgroundMusicList.add(new sf::Music());

	for (size_t i = 0; i < soundList.backMusic.size(); i++) 
	{
		backgroundMusicList.getId(i)->openFromFile(soundList.backMusic[i]);
		backgroundMusicList.getId(i)->setVolume(sv->SoundOptions.MusicVolume);
	}
}

void GameSound::bacgroundMusicProcessor() noexcept
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
