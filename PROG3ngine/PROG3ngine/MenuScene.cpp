#include "MenuScene.h"
#include "ButtonInputComponent.h"
#include <string>
#include "Audio.h"
#include "Locator.h"

MenuScene::MenuScene()
{
	//Load sounds 
	Audio* audio = Locator::getAudio();
	audio->addSound("slimeball.wav");
	audio->addSound("iceball.wav");
	audio->addSound("explode.wav");
	audio->addSound("Spacetime.mp3");
	audio->addSound("Engine.wav");

	audio->playSound(MUSIC, 25);

	GameObject* button = new GameObject(
		new PositionComponent(SCREEN_WIDTH / 2 - 242, SCREEN_HEIGHT / 2 - 50),
		new GraphicsComponent(std::string("47444.png"), SDL_Rect({ 9, 736, 242, 50 }), 2),
		new ButtonInputComponent());
	add(button);
	run();
}

void MenuScene::run()
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
				if (event.type == SDL_QUIT)
				{
					quit = true;
				}
			}

			//Calculate time step
			float timeStep = sys.stepTimer.getTicks() / 1000.f;

			//Clear screen
			SDL_SetRenderDrawColor(sys.getRenderer(), 255, 255, 255, 0);
			SDL_RenderClear(sys.getRenderer());

			//Render all GameObjects in gObjects
			for (GameObject* gO : getGObjects())
			{
				gO->update(timeStep);
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

MenuScene::~MenuScene()
{
}