#ifndef SYSTEM_H
#define SYSTEM_H

#include <SDL.h>
#include <SDL_ttf.h>
#include "Timer.h"


class System
{
public:
	System();
	SDL_Renderer* getRenderer() { return ren; }
	TTF_Font* getFont() { return font; }
	Timer fpsTimer, capTimer, stepTimer;
	~System();
private:
	SDL_Window* win;
	SDL_Renderer* ren;
	TTF_Font* font;
};

extern System sys;

#endif