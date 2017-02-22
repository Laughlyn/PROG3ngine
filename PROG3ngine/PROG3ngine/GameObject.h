#pragma once
#include "GraphicsComponent.h"
#include "InputComponent.h"
#include "Constants.h"

class GraphicsComponent;
class InputComponent;

class GameObject
{
public:
	float x = 0;
	float y = 0;
	float xVel = 0;
	float yVel = 0;
	void update(float timeStep);
	GameObject(GraphicsComponent* graphics, InputComponent* input);
	GraphicsComponent* getGraphicsComponent() { return graphics_; }
	~GameObject();
private:
	GraphicsComponent* graphics_;
	InputComponent* input_;
};