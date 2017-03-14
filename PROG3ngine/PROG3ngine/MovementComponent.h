#pragma once
#include "GameObject.h"

class MovementComponent
{
public:
	MovementComponent(float xVelocity, float yVelocity);
	MovementComponent();
	void update(GameObject& gameObject, float timeStep);
	float getXVel() { return xVel; }
	float getYVel() { return yVel; }
	void setXVel(float newXVel) { xVel = newXVel; }
	void setYVel(float newYVel) { yVel = newYVel; }
private:
	float xVel, yVel;
};