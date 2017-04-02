#pragma once
#include "GameObject.h"

class PositionComponent
{
public:
	PositionComponent(float x, float y);
	PositionComponent(float x, float y, float a);
	void update(GameObject & gameObject, float timeStep);
	inline float getX() { return x; }
	inline float getY() { return y; }
	inline float getAngle() { return angle; }
	inline void setX(float newX) { x = newX; }
	inline void setY(float newY) { y = newY; }
	inline void setAngle(float newAngle) { angle = newAngle; }
	virtual ~PositionComponent();
private:
	float x = 0;
	float y = 0;
	float angle = 0;
};