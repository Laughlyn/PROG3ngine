#pragma once
#ifndef SYSTEM_H
#define SYSTEM_H
#include <SDL.h>

class System
{
public:
	System();
	SDL_Renderer* getRenderer() { return ren; }
	~System();
private:
	SDL_Window* win;
	SDL_Renderer* ren;
};

extern System sys;

#endif