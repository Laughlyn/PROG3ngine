#pragma once
#include <list>
#include "Timer.h"
#include <SDL.h>
#include "System.h"
#include "Constants.h"
#include "GameObject.h"
#include <memory>


class Scene
{
public:
	virtual void scripts();
	void removeExpired();
	void add(std::unique_ptr<GameObject> gObject);
	virtual void run();
	std::list<std::unique_ptr<GameObject>> const &getGObjects() const;
	bool checkCollision(const SDL_Rect& a, const SDL_Rect& b);
	~Scene();
private:
	std::list<std::unique_ptr<GameObject>> gObjects;
};