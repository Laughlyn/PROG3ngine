#pragma once
#include "GameObject.h"
#include <SDL_image.h>
#include <string>
#include "System.h"

class GameObject;

class GraphicsComponent
{
public:
	GraphicsComponent(std::string path);
	GraphicsComponent(std::string path, SDL_Rect s, SDL_Rect d);
	void update(GameObject* gameObject);
	SDL_Rect* getdRect();
	~GraphicsComponent();

private:
	SDL_Texture* spriteTexture;
	SDL_Rect sRect;
	SDL_Rect dRect;
};