#include "VectorMovementComponent.h"



VectorMovementComponent::VectorMovementComponent()
{
}

VectorMovementComponent::VectorMovementComponent(float speed, float direction)
{
	vx = cos(direction) * speed;
	vy = sin(direction) * speed;
}

void VectorMovementComponent::update(GameObject & gameObject, float timeStep)
{
	gameObject.getPositionComponent()->setY(gameObject.getPositionComponent()->getY() + vx * timeStep);

	gameObject.getPositionComponent()->setX(gameObject.getPositionComponent()->getX() + vy * timeStep);
}

VectorMovementComponent::~VectorMovementComponent()
{
}
