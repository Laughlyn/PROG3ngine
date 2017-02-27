#pragma once
#include "GraphicsComponent.h"
#include "InputComponent.h"
#include "PositionComponent.h"
#include "Constants.h"
#include "Scene.h"

class GraphicsComponent;
class InputComponent;
class PositionComponent;
class Scene;

class GameObject
{
public:
	float xVel = 0;
	float yVel = 0;
	void update(float timeStep);
	virtual void scripts();
	GameObject(PositionComponent* position, GraphicsComponent* graphics, InputComponent* input);
	GameObject(PositionComponent* position, GraphicsComponent* graphics);
	GraphicsComponent* getGraphicsComponent() { if (graphics_)return graphics_; else return 0; }
	PositionComponent* getPositionComponent() { if (position_)return position_; else return 0; }
	void setScene(Scene* myScene) { myScene_ = myScene; }
	Scene* getScene() { if (myScene_)return myScene_; else return 0; }
	~GameObject();
private:
	Scene* myScene_;
	GraphicsComponent* graphics_;
	InputComponent* input_;
	PositionComponent* position_;
};