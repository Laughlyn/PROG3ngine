#include "DemoInputComponent.h"
#include "Constants.h"
#include "EnemyShipInputComponent.h"

void DemoInputComponent::update(GameObject& gameObject, float timeStep)
{
	SDL_PumpEvents();
	if (state[SDL_SCANCODE_K])
	{
		gameObject.setInputComponent(new EnemyShipInputComponent());
	}

	gameObject.getMovementComponent()->setXVel(-300.f);
	gameObject.getMovementComponent()->setYVel(0.f);
}
