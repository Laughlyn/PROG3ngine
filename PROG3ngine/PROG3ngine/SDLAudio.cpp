#include "SDLAudio.h"
#include <SDL_mixer.h>

SDLAudio::SDLAudio()
{
	
}

SDLAudio::~SDLAudio()
{

}

void SDLAudio::playSound(int soundID)
{
	Mix_PlayChannel(-1, sounds[soundID], 0);
}

void SDLAudio::stopSound(int soundID)
{
}

void SDLAudio::stopAllSounds()
{
}

void SDLAudio::addSound(std::string path)
{
	Mix_Chunk *sound = NULL;
	sound = Mix_LoadWAV(path.c_str());
	sounds.push_back(sound);
}

