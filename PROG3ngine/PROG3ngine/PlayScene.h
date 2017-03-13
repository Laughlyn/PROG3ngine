#pragma once
#include "Scene.h"
class PlayScene :
	public Scene
{
public:
	PlayScene();
	void createWave(int size);
	void scripts();
};