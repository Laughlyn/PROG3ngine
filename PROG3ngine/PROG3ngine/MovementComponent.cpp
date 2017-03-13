#include "MovementComponent.h"

class GameObject;

MovementComponent::MovementComponent(float xVelocity = 0, float yVelocity = 0) : xVel(xVelocity), yVel(yVelocity)
{
}

MovementComponent::MovementComponent() : xVel(0.f), yVel(0.f)
{
}


void MovementComponent::update(GameObject& gameObject, float timeStep)
{
	gameObject.getPositionComponent()->setY(gameObject.getPositionComponent()->getY() + yVel * timeStep);

	gameObject.getPositionComponent()->setX(gameObject.getPositionComponent()->getX() + xVel * timeStep);
}

MovementComponent::~MovementComponent()
{
}
