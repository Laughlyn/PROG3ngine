#include "PlayScene.h"
#include "PlayerGraphicsComponent.h"
#include "Player2InputComponent.h"
#include "Audio.h"
#include "Locator.h"
#include "PlayerInputComponent.h"
#include "InputComponent.h"


PlayScene::PlayScene()
{
	GameObject* background = new GameObject(
		new PositionComponent(0, 0), 
		new GraphicsComponent("blue.png", { 0, 0, 256, 256 }, {0, 0, 256, 256}));
	add(background);

	//Create player 1 (WASD)
	GameObject* player = new GameObject(
		new PositionComponent(200, 300), 
		new PlayerGraphicsComponent("47444.png", { 6, 21,  33, 16 }, { 0, 0, 32 * 4, 16 * 4 }),
		new PlayerInputComponent());
	add(player);


	//Create player 2 (ARROWS)
	GameObject* player2 = new GameObject(
		new PositionComponent(200, 600), 
		new PlayerGraphicsComponent("47444.png", { 6, 21, 33, 16 }, { 0 , 0, 32 * 4, 16 * 4 }),
		new Player2InputComponent());
	add(player2);

	//Load sounds 
	Audio* audio = Locator::getAudio();
	audio->addSound("slimeball.wav");
	audio->addSound("iceball.wav");

	run();
}

void PlayScene::run()
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
			for (GameObject* gO2 : getGObjects())
			{
				if (gO != gO2)
				{
					if (checkCollision(*gO->getGraphicsComponent()->getdRect(), *gO2->getGraphicsComponent()->getdRect()))
					{
						SDL_Log("Collision!");
					}
				}
			}
		}

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