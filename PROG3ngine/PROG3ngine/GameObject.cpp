#include "GameObject.h"

GameObject::GameObject(GraphicsComponent* graphics, InputComponent* input) : graphics_(graphics), input_(input)
{
	x = (float)graphics->getdRect()->x;
	y = (float)graphics->getdRect()->y;
}

void GameObject::update(float timeStep)
{
	y += yVel * timeStep;
	x += xVel * timeStep;
	xVel *= 0.99f;
	yVel *= 0.99f;
	input_->update(this);
	graphics_->update(this);
}

GameObject::~GameObject()
{
}
