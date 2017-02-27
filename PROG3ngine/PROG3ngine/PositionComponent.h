#pragma once
#include "GameObject.h"

class PositionComponent
{
public:
	PositionComponent(float x, float y);
	void update(GameObject* gameObject, float timeStep);
	float getX();
	float getY();
	void setX(float);
	void setY(float);
	~PositionComponent();
private:
	float x;
	float y;
};

