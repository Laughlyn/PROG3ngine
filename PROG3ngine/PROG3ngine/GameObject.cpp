#include "GameObject.h"

GameObject::GameObject(std::unique_ptr<PositionComponent> position, std::unique_ptr<MovementComponent> movement, std::shared_ptr<GraphicsComponent> graphics, std::unique_ptr<InputComponent> input, std::unique_ptr<PhysicsComponent> physics) : position_(std::move(position)), movement_(std::move(movement)), graphics_(graphics), input_(std::move(input)), physics_(std::move(physics))
{
}

GameObject::GameObject(std::unique_ptr<PositionComponent> position, std::shared_ptr<GraphicsComponent> graphics, std::unique_ptr<InputComponent> input, std::unique_ptr<PhysicsComponent> physics) : position_(std::move(position)), graphics_(graphics), input_(std::move(input)), physics_(std::move(physics))
{
}

GameObject::GameObject(std::unique_ptr<PositionComponent> position, std::unique_ptr<MovementComponent> movement, std::shared_ptr<GraphicsComponent> graphics, std::unique_ptr<PhysicsComponent> physics) : position_(std::move(position)), movement_(std::move(movement)), graphics_(graphics), physics_(std::move(physics))
{
}

GameObject::GameObject(std::unique_ptr<PositionComponent> position, std::shared_ptr<GraphicsComponent> graphics, std::unique_ptr<PhysicsComponent> physics) : position_(std::move(position)), graphics_(graphics), physics_(std::move(physics))
{
}

GameObject::GameObject(std::unique_ptr<PositionComponent> position, std::shared_ptr<GraphicsComponent> graphics, std::unique_ptr<InputComponent> input) : position_(std::move(position)), graphics_(graphics), input_(std::move(input))
{
}

GameObject::GameObject(std::unique_ptr<PositionComponent> position, std::shared_ptr<GraphicsComponent> graphics) : position_(std::move(position)), graphics_(graphics)
{
}

GameObject::GameObject(std::unique_ptr<PositionComponent> position, std::unique_ptr<MovementComponent> movement, std::shared_ptr<GraphicsComponent> graphics) : position_(std::move(position)), movement_(std::move(movement)), graphics_(graphics)
{
}


void GameObject::update(float timeStep)
{
	/*if (position_)
		position_->update(*this, timeStep);*/

	if(input_)
		input_->update(*this);

	if (movement_)
		movement_->update(*this, timeStep);

	if (physics_)
		physics_->update(*this, timeStep);

	scripts();

	if (graphics_)
		graphics_->update(*this);
}

void GameObject::scripts()
{

}
