#pragma once
#include "GameObject.h"
#include <memory>

class PhysicsComponent
{
public:
	PhysicsComponent(SDL_Rect hB, int b, int f, int m);
	void update(GameObject& gameObject, float timeStep);
	void collision(std::unique_ptr<GameObject> gO, std::unique_ptr<GameObject> otherGO);
	SDL_Rect getHitBox();
private:
	int offX, offY, bounce, friction, mass;
	SDL_Rect hitBox = { 0,0,0,0 };
};

