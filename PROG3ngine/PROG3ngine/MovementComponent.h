#ifndef MOVEMENTCOMPONENT_H
#define MOVEMENTCOMPONENT_H
#include "GameObject.h"

class MovementComponent
{
public:
	MovementComponent(float xVelocity, float yVelocity);
	MovementComponent();
	virtual void update(GameObject & gameObject, float timeStep);
	inline float getXVel() { return xVel; }
	inline float getYVel() { return yVel; }
	inline void setXVel(float newXVel) { xVel = newXVel; }
	inline void setYVel(float newYVel) { yVel = newYVel; }
	virtual inline void accelerate(float ax, float ay) { }
	virtual ~MovementComponent();
private:
	float xVel = 0;
	float yVel = 0;
};

#endif