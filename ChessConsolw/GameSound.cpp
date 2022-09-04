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
	sound.setVolume(_defaultVolume);
	sound.play();
}

void GameSound::play(sf::Sound& sound, short volume)
{
	sound.setVolume(volume);
	sound.play();
	sound.setVolume(_defaultVolume);
}

GameSound::GameSound()
{
	buffer_movePiece.loadFromFile(soundList.pieceMove);
	sound_movePiece.setBuffer(buffer_movePiece);

	buffer_gameStart.loadFromFile(soundList.gameStart);
	sound_gameStart.setBuffer(buffer_gameStart);
}
