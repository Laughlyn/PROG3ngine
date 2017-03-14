#pragma once
#include "GraphicsComponent.h"
#include "InputComponent.h"
#include "PositionComponent.h"
#include "Constants.h"
#include "Scene.h"
#include "PhysicsComponent.h"
#include "MovementComponent.h"
#include <memory>

class GraphicsComponent;
class InputComponent;
class PositionComponent;
class Scene;
class PhysicsComponent;
class MovementComponent;

class GameObject
{
public:
	bool expired() { return hasExpired; }
	void expire() { hasExpired = true; }
	virtual void update(float timeStep);
	virtual void scripts();

	GameObject(std::unique_ptr<PositionComponent> position, std::unique_ptr<MovementComponent> movement, std::shared_ptr<GraphicsComponent> graphics, std::unique_ptr<InputComponent> input, std::unique_ptr<PhysicsComponent> physics);
	GameObject(std::unique_ptr<PositionComponent> position, std::shared_ptr<GraphicsComponent> graphics, std::unique_ptr<InputComponent> input, std::unique_ptr<PhysicsComponent> physics);
	GameObject(std::unique_ptr<PositionComponent> position, std::unique_ptr<MovementComponent> movement, std::shared_ptr<GraphicsComponent> graphics, std::unique_ptr<PhysicsComponent> physics);
	GameObject(std::unique_ptr<PositionComponent> position, std::shared_ptr<GraphicsComponent> graphics, std::unique_ptr<PhysicsComponent> physics);
	GameObject(std::unique_ptr<PositionComponent> position, std::shared_ptr<GraphicsComponent> graphics, std::unique_ptr<InputComponent> input);
	GameObject(std::unique_ptr<PositionComponent> position, std::unique_ptr<MovementComponent> movement, std::shared_ptr<GraphicsComponent> graphics);
	GameObject(std::unique_ptr<PositionComponent> position, std::shared_ptr<GraphicsComponent> graphics);

	std::shared_ptr<GraphicsComponent> & getGraphicsComponent()	{ return graphics_; }
	std::unique_ptr<PositionComponent> & getPositionComponent() { return position_;	}
	std::unique_ptr<PhysicsComponent> &	getPhysicsComponent()	{ return physics_;	}
	std::unique_ptr<MovementComponent> & getMovementComponent()	{ return movement_;	}

	void setScene(std::shared_ptr<Scene> myScene) { myScene_ = myScene; }
	std::shared_ptr<Scene> getScene() { return myScene_; }
private:
	bool hasExpired = false;
	std::shared_ptr<Scene> myScene_;
	std::shared_ptr<GraphicsComponent> graphics_;
	std::unique_ptr<InputComponent> input_;
	std::unique_ptr<PositionComponent> position_;
	std::unique_ptr<MovementComponent> movement_;
	std::unique_ptr<PhysicsComponent> physics_;
};