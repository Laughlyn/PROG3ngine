#pragma once
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <SDL.h>

class GameObject
{
public:
	virtual void draw() = 0;
	virtual void tick(float timeStep) {}
	virtual void collision(float timeStep, GameObject*) {}
	virtual ~GameObject();
	virtual void mouseDown(const SDL_Event&) {}
	virtual void mouseUp(const SDL_Event&) {}
	virtual void keyDown(const SDL_Event&) {}
	virtual void keyUp(const SDL_Event&) {}
	SDL_Rect getRect() { return rect; }
	void setRect(SDL_Rect newRect) { rect = newRect; }
protected:
	GameObject(const SDL_Rect& r);
	SDL_Rect rect;
private:
	GameObject(const GameObject&) = delete;
	const GameObject& operator=(const GameObject&) = delete;
};
#endif