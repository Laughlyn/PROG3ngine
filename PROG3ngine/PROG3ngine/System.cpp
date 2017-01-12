#pragma once
#include "Constants.h"
#include "System.h"
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

System::System()
{
	//Init SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	IMG_Init(IMG_INIT_PNG);

	IMG_Init(IMG_INIT_JPG);

	//Create window
	win = SDL_CreateWindow("PROG3ngine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);

	//Create renderer
	ren = SDL_CreateRenderer(win, -1, 0);
}

System::~System()
{
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();
}

System sys;