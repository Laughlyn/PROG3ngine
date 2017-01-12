#include "Scene.h"
#include <SDL.h>
#include "System.h"

void Scene::add(GameObject* gObject)
{
	gObjects.push_back(gObject);
}

void Scene::run()
{
	//Clear screen
	SDL_RenderClear(sys.getRenderer());

	//Render all GameObjects in gObjects
	for (GameObject* gO : gObjects)
	{
		gO->draw();
	}
	SDL_RenderPresent(sys.getRenderer());
}

Scene::~Scene()
{
	for (GameObject* gO : gObjects)
	{
		delete gO;
	}
}
