#pragma once
#include "GameObject.h"

class PhysicsComponent
{
public:
	PhysicsComponent(SDL_Rect & hB, int b, int f, int m);
	void update(GameObject & gameObject, float timeStep);
	void collision(GameObject & gO, GameObject & otherGO);
	SDL_Rect getHitBox();
	virtual ~PhysicsComponent();
private:
	int offX, offY, bounce, friction, mass;
	SDL_Rect hitBox = { 0,0,0,0 };
};

