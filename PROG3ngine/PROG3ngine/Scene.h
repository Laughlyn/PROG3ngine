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
	virtual void scripts();
	void removeExpired();
	void add(GameObject* gObject);
	virtual void run();
	std::list<GameObject*>const &getGObjects() const;
	bool checkCollision(const SDL_Rect& a, const SDL_Rect& b);
	~Scene();
private:
	std::list<GameObject*> gObjects;
};