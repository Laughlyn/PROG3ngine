#ifndef LOCATOR_H
#define LOCATOR_H

#include "Audio.h"

class Locator
{
public:
	Locator();
	static Audio* getAudio();
	static void provide(Audio* service);
	~Locator();
private:
	static Audio* service_;
};

#endif