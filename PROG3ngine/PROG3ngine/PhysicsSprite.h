#ifndef PHYSICSSPRITE_H
#define PHYSICSSPRITE_H
#include "DynamicSprite.h"

class PhysicsSprite :
	public DynamicSprite
{
public:
	PhysicsSprite(const SDL_Rect r, std::string t);
	void tick(int timeStep);
	~PhysicsSprite();
};

#endif