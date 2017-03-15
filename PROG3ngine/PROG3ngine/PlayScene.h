#pragma once
#include "Scene.h"
class PlayScene :
	public Scene
{
public:
	PlayScene();
	void createWave(int size);
	void createStars();
	void scripts();
private:
		SDL_Texture* textureAtlas;
};