#include "GameObject.h"

GameObject::GameObject(PositionComponent* position, MovementComponent* movement, GraphicsComponent* graphics, InputComponent* input, PhysicsComponent* physics) : position_(position), movement_(movement), graphics_(graphics), input_(input), physics_(physics)
{
}

GameObject::GameObject(PositionComponent* position, GraphicsComponent* graphics, InputComponent* input, PhysicsComponent* physics) : position_(position), graphics_(graphics), input_(input), physics_(physics)
{
}

GameObject::GameObject(PositionComponent * position, MovementComponent * movement, GraphicsComponent * graphics, PhysicsComponent * physics) : position_(position), movement_(movement), graphics_(graphics), physics_(physics)
{
}

GameObject::GameObject(PositionComponent * position, GraphicsComponent * graphics, PhysicsComponent * physics) : position_(position), graphics_(graphics), physics_(physics)
{
}

GameObject::GameObject(PositionComponent* position, GraphicsComponent* graphics, InputComponent* input) : position_(position), graphics_(graphics), input_(input)
{
}

GameObject::GameObject(PositionComponent* position, GraphicsComponent* graphics) : position_(position), graphics_(graphics)
{
}

GameObject::GameObject(PositionComponent* position, MovementComponent* movement, GraphicsComponent* graphics) : position_(position), movement_(movement), graphics_(graphics)
{
}


void GameObject::update(float timeStep)
{
	/*if (position_)
		position_->update(*this, timeStep);*/

	if(input_)
		input_->update(*this, timeStep);

	if (movement_)
		movement_->update(*this, timeStep);

	if (physics_)
		physics_->update(*this, timeStep);

	scripts();

	if (graphics_)
		graphics_->update(*this, timeStep);

	if (getPositionComponent()->getX() < -100)
		expire();
}

void GameObject::scripts()
{

}

GameObject::~GameObject()
{
	delete graphics_;
	delete input_;
	delete position_;
	delete physics_;
	delete movement_;
}

void GameObject::onExpiration()
{

}