#pragma once
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <SDL.h>

class GameObject
{
public:
	GameObject(const SDL_Rect& r);
	virtual void draw(); //= 0;
	~GameObject();
private:
	SDL_Rect rect;
};

#endif
