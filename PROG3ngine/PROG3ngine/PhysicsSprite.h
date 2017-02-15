#ifndef PHYSICSSPRITE_H
#define PHYSICSSPRITE_H
#include "DynamicSprite.h"

class PhysicsSprite :
	public DynamicSprite
{
public:
	PhysicsSprite(const SDL_Rect r, std::string t);
	void update(float timeStep);
	//void move(float timeStep);
	void collision(float timeStep, GameObject* gO);
	void physics(float timeStep);
	~PhysicsSprite();

private:
	bool collided = false;
};

#endif