#pragma once
#include <list>
#include "Timer.h"
#include <SDL.h>
#include "System.h"
#include "Constants.h"
#include "GameObject.h"

class Scene
{
public:
	void add(GameObject* gObject);
	void run();
	/*bool checkCollision(SDL_Rect a, SDL_Rect b);*/
	~Scene();
private:
	std::list<GameObject*> gObjects;
	//The frames per second timer
	Timer fpsTimer, capTimer, stepTimer;
};