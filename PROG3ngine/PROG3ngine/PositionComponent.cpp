#include "PositionComponent.h"


PositionComponent::PositionComponent(float x, float y) : x(x), y(y)
{
}

PositionComponent::PositionComponent(float x, float y, float a) : x(x), y(y), angle(a)
{
}

void PositionComponent::update(GameObject& gameObject, float timeStep)
{

}

PositionComponent::~PositionComponent()
{
}
