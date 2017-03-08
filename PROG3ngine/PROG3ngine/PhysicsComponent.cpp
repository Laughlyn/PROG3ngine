#include "PhysicsComponent.h"



PhysicsComponent::PhysicsComponent(int b, int f, int m) : bounce(b), friction(f), mass(m)
{

}

void PhysicsComponent::update(GameObject& gameObject, float timeStep)
{
	gameObject.getPositionComponent()->setY(gameObject.getPositionComponent()->getY() + gameObject.yVel * timeStep);
}

PhysicsComponent::~PhysicsComponent()
{
}
