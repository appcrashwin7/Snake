#pragma once
#include <SFML\Audio.hpp>

using sf::Sound;
using sf::SoundBuffer;

class AudioManager
{
	Sound *sound_eat;
	SoundBuffer buffer_of_sound_eat;

public:
	AudioManager();
	void play_audio();
	~AudioManager();

};