#pragma once
#ifndef SCENE_H
#define SCENE_H
#include <vector>
#include "GameObject.h"

class Scene
{
public:
	void add(GameObject* gObject);
	void run();
	~Scene();
private:
	std::vector<GameObject*> gObjects;
};

#endif