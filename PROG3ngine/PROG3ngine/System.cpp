#pragma once
#include "SDLAudio.h"
#include "Locator.h"
#include "Constants.h"
#include "System.h"
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <stdexcept>
#include <SDL_mixer.h>



System::System()
{
	//Init SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	IMG_Init(IMG_INIT_PNG);

	IMG_Init(IMG_INIT_JPG);

	//Create window
	win = SDL_CreateWindow("PROG3ngine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);

	if (V_SYNC)
	{
		//Create renderer with vsync
		ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	}
	else
	{
		//Create renderer
		ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
	}

	//Initialize TTF
	TTF_Init();
	font = TTF_OpenFont("c:/windows/fonts/arial.ttf", 24);
	if (font == nullptr)
	{
		throw std::runtime_error(std::string("Fontfel: ") + SDL_GetError());
	}

	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	SDLAudio *audio = new SDLAudio();
	Locator::provide(audio);

}

System::~System()
{
	Mix_CloseAudio();
	Mix_Quit();
	TTF_CloseFont(font);
	TTF_Quit();
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();
}

System sys;