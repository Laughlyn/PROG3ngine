#include "PositionComponent.h"


PositionComponent::PositionComponent(float x, float y) : x(x), y(y)
{
}

void PositionComponent::update(GameObject& gameObject, float timeStep)
{

}

float PositionComponent::getX()
{
	return x;
}

float PositionComponent::getY()
{
	return y;
}

void PositionComponent::setX(float newX)
{
	x = newX;
}

void PositionComponent::setY(float newY)
{
	y = newY;
}
