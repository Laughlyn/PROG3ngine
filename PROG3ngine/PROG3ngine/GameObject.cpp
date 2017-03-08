#include "GameObject.h"

GameObject::GameObject(PositionComponent* position, GraphicsComponent* graphics, InputComponent* input) : position_(position), graphics_(graphics), input_(input)
{
}

GameObject::GameObject(PositionComponent* position, GraphicsComponent* graphics) : position_(position), graphics_(graphics)
{
}

void GameObject::update(float timeStep)
{
	if (position_)
		position_->update(*this, timeStep);

	if(input_)
		input_->update(*this);

	if(graphics_)
		graphics_->update(*this);

	if (physics_)
		physics_->update(*this, timeStep);

	scripts();
}

void GameObject::scripts()
{

}

GameObject::~GameObject()
{
	delete graphics_;
	delete input_;
	delete position_;
}
