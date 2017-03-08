#pragma once
#include "InputComponent.h"
#include <SDL.h>

#include <SDL_image.h>
#include <stdio.h>
#include <string>

class PlayerInputComponent :
	public InputComponent
{
public:
	virtual void update(GameObject& gameObject);
	const Uint8 *state = SDL_GetKeyboardState(NULL);
	//Our test callback function
	Uint32 callback(Uint32 interval, void* param);
};