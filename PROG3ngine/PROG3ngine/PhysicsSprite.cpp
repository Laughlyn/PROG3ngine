#include "PhysicsSprite.h"

PhysicsSprite::PhysicsSprite(const SDL_Rect r, std::string t) : DynamicSprite(r, t)
{

}

void PhysicsSprite::tick(float timeStep)
{
	move(timeStep);
	physics(timeStep);
}

void PhysicsSprite::collision(float timeStep, GameObject* gO)
{
	tick(-timeStep);
	gO->getRect();
	//velX = 0;
	//velY = 0;
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
