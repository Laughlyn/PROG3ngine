#pragma once
#include "InputComponent.h"
#include <SDL.h>

class PlayerInputComponent :
	public InputComponent
{
public:
	virtual void update(GameObject* gameObject);
	const Uint8 *state = SDL_GetKeyboardState(NULL);
};