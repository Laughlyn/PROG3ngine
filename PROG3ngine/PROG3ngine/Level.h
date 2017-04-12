#pragma once
#include <vector>
#include <SDL.h>
#include "Scene.h"

class Level
{
public:
	Level(Scene* newScene);
	~Level();
private:
	std::vector<SDL_Texture*> textures;
	virtual void init();
	Scene* scene;
};