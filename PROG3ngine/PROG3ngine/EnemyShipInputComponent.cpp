#include "EnemyShipInputComponent.h"
#include "DemoInputComponent.h"
#include "MovementComponent.h"

EnemyShipInputComponent::EnemyShipInputComponent()
{

}

void EnemyShipInputComponent::update(GameObject& gameObject, float timeStep)
{
	SDL_PumpEvents();
	if (state[SDL_SCANCODE_L])
	{
		gameObject.setInputComponent(new DemoInputComponent());
	}

	//Bob up and down
	gameObject.getMovementComponent()->setXVel(-300.f);
	gameObject.getMovementComponent()->setYVel(std::sin(angle) * 300.f);
	angle += 2.f * timeStep;
}

EnemyShipInputComponent::~EnemyShipInputComponent()
{
}
