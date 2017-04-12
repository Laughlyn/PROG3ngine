#ifndef AUDIO_H
#define AUDIO_H

#include <string>

class Audio
{
public:
	Audio();
	virtual void playSound(int soundID) = 0;
	virtual void playSound(int soundID, int volume) = 0;
	virtual void stopSound(int soundID) = 0;
	virtual void stopAllSounds() = 0;
	virtual void addSound(std::string path) = 0;
	~Audio();
};
#endif