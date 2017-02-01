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
	if()
	velX = 0;
	velY = 0;
}

//void PhysicsSprite::move(float timeStep)
//{
//
//	velX += accelX * timeStep;
//	velY += accelY * timeStep;
//
//	//Move
//	posX += velX * timeStep;
//	rect.x = int(posX);
//
//
//
//	posY += velY * timeStep;
//	rect.y = int(posY);
//
//}

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
