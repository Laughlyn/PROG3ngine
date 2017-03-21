#include "Scene.h"
#include "Audio.h"
#include "Locator.h"

void Scene::scripts()
{

}

void Scene::add(GameObject* gObject)
{
	gObject->setScene(*this);
	gObjects.emplace_back(gObject);
}

void Scene::run()
{
	bool quit = false;
	SDL_Event event;

	//Start counting frames per second
	int countedFrames = 0;
	sys.fpsTimer.start();

	while (!quit)
	{
		//Start cap timer
		sys.capTimer.start();

		//Calculate and correct fps
		float avgFPS = countedFrames / (sys.fpsTimer.getTicks() / 1000.f);
		if (avgFPS > 2000000)
		{
			avgFPS = 0;
		}

		char array[100];
		sprintf_s(array, "%f", avgFPS);

		SDL_Log(array);

		while (SDL_PollEvent(&event) != 0)
		{
			//Handle events
			if (event.key.keysym.sym == SDLK_ESCAPE)
			{
				quit = true;
			}

			// Create custom pause Scene!
			//if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_ESCAPE)
			//{
			//	Scene pause;
			//	pause.run();
			//}
		}

		//Calculate time step
		float timeStep = sys.stepTimer.getTicks() / 1000.f;

		//Clear screen
		SDL_SetRenderDrawColor(sys.getRenderer(), 0, 0, 0, 0);
		SDL_RenderClear(sys.getRenderer());


		//Render all GameObjects in gObjects
		for (GameObject* gO : getGObjects())
		{
			gO->update(timeStep);

			//Check if object is colliding
			if (gO->getPhysicsComponent() != nullptr)
			{
				for (GameObject* gO2 : getGObjects())
				{
					if (gO != gO2 && gO->getPhysicsComponent() != nullptr && gO2->getPhysicsComponent() != nullptr)
					{
						if (checkCollision(gO->getPhysicsComponent()->getHitBox(), gO2->getPhysicsComponent()->getHitBox()))
						{
							SDL_Log("Collision!");
							gO->getPhysicsComponent()->collision(*gO, *gO2);
							gO2->getPhysicsComponent()->collision(*gO2, *gO);
						}
					}
				}
			}
		}

		//Remove expired GameObjects from Scene
		removeExpired();


		scripts();

		//Restart step timer
		sys.stepTimer.start();

		//Update screen
		SDL_RenderPresent(sys.getRenderer());

		++countedFrames;

		//If frame finished early
		int frameTicks = sys.capTimer.getTicks();
		if (frameTicks < SCREEN_TICKS_PER_FRAME)
		{
			//Wait remaining time
			SDL_Delay(SCREEN_TICKS_PER_FRAME - frameTicks);
		}
	}
}

std::list<GameObject*> const & Scene::getGObjects() const
{
	return gObjects;
}

//True if rects are colliding
bool Scene::checkCollision(const SDL_Rect& a, const SDL_Rect& b)
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

void Scene::removeExpired()
{
	for (auto i = gObjects.cbegin(); i != gObjects.cend();) 
	{
		if ((*i)->expired())
		{
			i = gObjects.erase(i);
		}
		else
			++i;
	}
}

Scene::~Scene()
{
	for (GameObject* gO : gObjects)
	{
		delete gO;
	}
}