#pragma once
#include "GraphicsComponent.h"
#include "InputComponent.h"
#include "PositionComponent.h"
#include "Constants.h"
#include "Scene.h"
#include "PhysicsComponent.h"

class GraphicsComponent;
class InputComponent;
class PositionComponent;
class Scene;
class PhysicsComponent;

class GameObject
{
public:
	float xVel = 0;
	float yVel = 0;
	bool expired() { return hasExpired; }
	void expire() { hasExpired = true; }
	void update(float timeStep);
	virtual void scripts();
	GameObject(PositionComponent* position, GraphicsComponent* graphics, InputComponent* input);
	GameObject(PositionComponent* position, GraphicsComponent* graphics);
	GraphicsComponent* getGraphicsComponent() { if (graphics_)return graphics_; else return nullptr; }
	PositionComponent* getPositionComponent() { if (position_)return position_; else return nullptr; }
	void setScene(Scene* myScene) { myScene_ = myScene; }
	Scene* getScene() { if (myScene_)return myScene_; else return nullptr; }
	~GameObject();
private:
	bool hasExpired = false;
	Scene* myScene_;
	GraphicsComponent* graphics_;
	InputComponent* input_;
	PositionComponent* position_;
	PhysicsComponent* physics_;
};