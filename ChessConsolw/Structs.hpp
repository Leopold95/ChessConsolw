#pragma once

#include <string>
#include <vector>

using std::string;


namespace Structs
{
	struct SoundOptions
	{
		short MusicVolume = 0;
		short SoundsVolume = 60;
	};

	struct SoundList
	{
		SoundList()
		{
			//add here line to add background sound
			backMusic.push_back("Assets/Music/backgrpund.wav");
			backMusic.push_back("Assets/Music/background2.wav");
			backMusic.push_back("Assets/Music/zhiend/fallin.mp3");
		}

		const string pieceMove = "Assets/Sounds/piecemoved.wav";
		const string music_gameStart = "Assets/Music/gamestart.wav";
		std::vector<string>  backMusic;
	};
}