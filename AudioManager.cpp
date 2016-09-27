#include "AudioManager.h"

AudioManager::AudioManager()
{
	buffer_of_sound_eat.loadFromFile("eat_apple.wav");
	sound_eat = new Sound;
	sound_eat->setBuffer(buffer_of_sound_eat);
}

void AudioManager::play_audio()
{
	sound_eat->play();
}

AudioManager::~AudioManager()
{
	delete sound_eat;
}
