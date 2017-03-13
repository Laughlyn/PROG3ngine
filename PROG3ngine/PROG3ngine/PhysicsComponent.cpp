#include "PhysicsComponent.h"

class GameObject;

PhysicsComponent::PhysicsComponent(SDL_Rect hB, int b, int f, int m) : hitBox(hB), bounce(b), friction(f), mass(m)
{
	offX = hB.x;
	offY = hB.y;
}

void PhysicsComponent::update(GameObject& gameObject, float timeStep)
{
	gameObject.getPositionComponent()->setY(gameObject.getPositionComponent()->getY() + 400 * timeStep * mass);

	hitBox = {(int)gameObject.getPositionComponent()->getX() + offX, (int)gameObject.getPositionComponent()->getY() + offY, hitBox.w, hitBox.h};
}

void PhysicsComponent::collision(GameObject* gO, GameObject* otherGO)
{
	gO->expire();
}

SDL_Rect PhysicsComponent::getHitBox()
{
	return hitBox;
}

PhysicsComponent::~PhysicsComponent()
{
}
