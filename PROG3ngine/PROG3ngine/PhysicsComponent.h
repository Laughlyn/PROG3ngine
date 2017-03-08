#pragma once
#include "GameObject.h"

class PhysicsComponent
{
public:
	PhysicsComponent(int b, int f, int m);
	void update(GameObject& gameObject, float timeStep);
	~PhysicsComponent();
private:
	int bounce, friction, mass;
};

