#include "SoundSystem.h"

void SoundSystem::play(std::string name)
{
	bool sucsess = buffer.loadFromFile(name);

	if (sucsess == false)
		_logger.WriteFile("Error while opening sound file. Sound file name: " + name);

	sound.resetBuffer();
	sound.setBuffer(buffer);

	sound.setVolume(40);
	sound.play();
}
