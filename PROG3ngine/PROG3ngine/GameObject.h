#pragma once
#include "GraphicsComponent.h"
#include "InputComponent.h"
#include "PositionComponent.h"
#include "Constants.h"
#include "Scene.h"
#include "PhysicsComponent.h"
#include "MovementComponent.h"

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
	void expire() { hasExpired = true; onExpiration(); }
	void update(float timeStep);
	virtual void scripts();

	GameObject(PositionComponent* position, MovementComponent* movement, GraphicsComponent* graphics, InputComponent* input, PhysicsComponent* physics);
	GameObject(PositionComponent* position, GraphicsComponent* graphics, InputComponent* input, PhysicsComponent* physics);
	GameObject(PositionComponent* position, MovementComponent* movement, GraphicsComponent* graphics, PhysicsComponent* physics);
	GameObject(PositionComponent* position, GraphicsComponent* graphics, PhysicsComponent* physics);
	GameObject(PositionComponent* position, GraphicsComponent* graphics, InputComponent* input);
	GameObject(PositionComponent* position, MovementComponent* movement, GraphicsComponent* graphics);
	GameObject(PositionComponent* position, GraphicsComponent* graphics);

	GraphicsComponent*	getGraphicsComponent()&	{ if (graphics_)	return graphics_;	else return nullptr; }
	PositionComponent*	getPositionComponent()&	{ if (position_)	return position_;	else return nullptr; }
	PhysicsComponent*	getPhysicsComponent()&	{ if (physics_)		return physics_;	else return nullptr; }
	MovementComponent*	getMovementComponent()&	{ if (movement_)	return movement_;	else return nullptr; }

	void setGraphicsComponent(GraphicsComponent* graphics) { graphics_ = graphics; }

	void setScene(Scene& myScene) { myScene_ = &myScene; }
	Scene* getScene() { if (myScene_)return myScene_; else return nullptr; }
	~GameObject();
private:
	virtual void onExpiration();
	bool hasExpired = false;
	Scene* myScene_;
	GraphicsComponent* graphics_ = nullptr;
	InputComponent* input_ = nullptr;
	PositionComponent* position_ = nullptr;
	MovementComponent* movement_ = nullptr;
	PhysicsComponent* physics_ = nullptr;
};