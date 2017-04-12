#include "PhysicsComponent.h"

class GameObject;

//hitBox Rect {xOffset, yOffset, width, height}, Bounce, friction, mass
PhysicsComponent::PhysicsComponent(SDL_Rect & hB, int b, int f, int m) : hitBox(hB), bounce(b), friction(f), mass(m)
{
	offX = hB.x;
	offY = hB.y;
}

void PhysicsComponent::update(GameObject& gameObject, float timeStep)
{
	gameObject.getMovementComponent()->accelerate(0, (timeStep * ((float)mass / 100.f) * gravity * 500.f));
	hitBox = {(int)gameObject.getPositionComponent()->getX() + offX, (int)gameObject.getPositionComponent()->getY() + offY, hitBox.w, hitBox.h};
}

void PhysicsComponent::collision(GameObject& gO, GameObject& otherGO)
{
	gO.expire();
}

SDL_Rect PhysicsComponent::getHitBox()
{
	return hitBox;
}

PhysicsComponent::~PhysicsComponent()
{
}
