#include "GameObject.h"

GameObject::GameObject(GraphicsComponent* graphics, InputComponent* input) : graphics_(graphics), input_(input)
{
	x = (float)graphics->getdRect()->x;
	y = (float)graphics->getdRect()->y;
}

void GameObject::update(float timeStep)
{
	y += yVel * timeStep;
	if (y < 0)
	{
		y = 0;
	}
	if (y > SCREEN_HEIGHT - 64)
	{
		y = SCREEN_HEIGHT - 64;
	}

	x += xVel * timeStep;
	if (x < 0)
	{
		x = 0;
	}
	if (x > SCREEN_WIDTH - 128)
	{
		x = SCREEN_WIDTH - 128;
	}

	xVel *= 0.99f;
	yVel *= 0.99f;
	input_->update(this);
	graphics_->update(this);
}

GameObject::~GameObject()
{
}
