#include "Scene.h"
#include <SDL.h>
#include "System.h"
#include "Constants.h"
#include "DynamicSprite.h"
#include "GameObject.h"

void Scene::add(GameObject* gObject)
{
	gObjects.push_back(gObject);
}

void Scene::run()
{
	bool quit = false;
	SDL_Event event;

	//Start counting frames per second
	int countedFrames = 0;
	fpsTimer.start();

	while (!quit)
	{
		//Start cap timer
		capTimer.start();

		//Calculate and correct fps
		float avgFPS = countedFrames / (fpsTimer.getTicks() / 1000.f);
		if (avgFPS > 2000000)
		{
			avgFPS = 0;
		}

		while (SDL_PollEvent(&event) != 0)
		{
			//Handle events
			if (event.type == SDL_QUIT)
			{
				quit = true;
			}
			if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				for (auto gO : gObjects)
				{
					gO->mouseDown(event);
				}
			}
			if (event.type == SDL_MOUSEBUTTONUP)
			{
				for (auto gO : gObjects)
				{
					gO->mouseUp(event);
				}
			}
			if (event.type == SDL_KEYDOWN)
			{
				for (auto gO : gObjects)
				{
					gO->keyDown(event);
				}
			}
			if (event.type == SDL_KEYUP)
			{
				for (auto gO : gObjects)
				{
					gO->keyUp(event);
				}
			}
		}

		//Calculate time step
		float timeStep = stepTimer.getTicks() / 1000.f;

		//Clear screen
		SDL_SetRenderDrawColor(sys.getRenderer(), 255, 255, 255, 0);
		SDL_RenderClear(sys.getRenderer());

		//Render all GameObjects in gObjects
		for (GameObject* gO : gObjects)
		{
			gO->tick(timeStep);

			for (GameObject* gO2 : gObjects)
			{
				if (gO != gO2)
				{
					if (checkCollision(gO->getRect(), gO2->getRect()))
					{
						gO->collision(timeStep, gO2);
					}
				}
			}
			gO->draw();
		}

		//Remove objects out of bounds
		std::list<GameObject*>::iterator i = gObjects.begin();

		while (i != gObjects.end())
		{
			if ((*i)->getRect().y < -100 || (*i)->getRect().x < -100 || (*i)->getRect().x > SCREEN_WIDTH + 100 || (*i)->getRect().y > SCREEN_HEIGHT + 100)
			{
				i = gObjects.erase(i);
			}
			else
			{
				i++;
			}
		}

		//Restart step timer
		stepTimer.start();

		//Update screen
		SDL_RenderPresent(sys.getRenderer());

		++countedFrames;

		//If frame finished early
		int frameTicks = capTimer.getTicks();
		if (frameTicks < SCREEN_TICKS_PER_FRAME)
		{
			//Wait remaining time
			SDL_Delay(SCREEN_TICKS_PER_FRAME - frameTicks);
		}
	}
}

//True if rects are colliding
bool Scene::checkCollision(SDL_Rect a, SDL_Rect b)
{
	int leftA, rightA, topA, bottomA;
	leftA = a.x;
	rightA = a.x + a.w;
	topA = a.y;
	bottomA = a.y + a.h;

	int leftB, rightB, topB, bottomB;
	leftB = b.x;
	rightB = b.x + b.w;
	topB = b.y;
	bottomB = b.y + b.h;

	if (bottomA <= topB)
	{
		return false;
	}

	if (topA >= bottomB)
	{
		return false;
	}

	if (rightA <= leftB)
	{
		return false;
	}

	if (leftA >= rightB)
	{
		return false;
	}

	return true;
}

Scene::~Scene()
{
	for (GameObject* gO : gObjects)
	{
		delete gO;
	}
}
