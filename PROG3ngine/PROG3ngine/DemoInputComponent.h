#pragma once
#include "InputComponent.h"

class DemoInputComponent :
	public InputComponent
{
public:
	virtual void DemoInputComponent::update(GameObject& gameObject, float timeStep);
private:
	const Uint8 *state = SDL_GetKeyboardState(NULL);
};

