#pragma once
#include "InputComponent.h"
class EnemyShipInputComponent :
	public InputComponent
{
public:
	EnemyShipInputComponent();
	void update(GameObject & gameObject, float timeStep);
	~EnemyShipInputComponent();
private:
	float angle = 0.f;
	const Uint8 *state = SDL_GetKeyboardState(NULL);
};

