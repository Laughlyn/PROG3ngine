#pragma once
#include "Audio.h"
#include <vector>
#include <SDL_mixer.h>

class SDLAudio :
	public Audio
{
public:
	SDLAudio();
	virtual void playSound(int soundID);
	virtual void playSound(int soundID, int volume);
	virtual void stopSound(int soundID);
	virtual void stopAllSounds();
	virtual void addSound(std::string path);
	~SDLAudio();
private:
	std::vector<Mix_Chunk*> sounds;
};

