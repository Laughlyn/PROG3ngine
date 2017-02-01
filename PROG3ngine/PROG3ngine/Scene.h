#pragma once
#ifndef SCENE_H
#define SCENE_H
#include <list>
#include "GameObject.h"
#include "Timer.h"

class Scene
{
public:
	void add(GameObject* gObject);
	void run();
	bool checkCollision(SDL_Rect a, SDL_Rect b);
	~Scene();
private:
	std::list<GameObject*> gObjects;
	//The frames per second timer
	Timer fpsTimer, capTimer, stepTimer;
};

#endif