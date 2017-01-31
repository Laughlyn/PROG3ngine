#include "PhysicsSprite.h"

PhysicsSprite::PhysicsSprite(const SDL_Rect r, std::string t) : DynamicSprite(r, t)
{

}

void PhysicsSprite::tick(float timeStep)
{
	move(timeStep);
	physics(timeStep);
}

void PhysicsSprite::physics(float timeStep)
{
	// "Gravity"
	velY += 1000.f * timeStep;

	//Friction
	velX *= 0.99f;
}

PhysicsSprite::~PhysicsSprite()
{

}
