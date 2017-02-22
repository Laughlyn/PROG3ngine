#include "ButtonInputComponent.h"
#include <string>
#include "Scene.h"
#include "Locator.h"
#include "PlayerInputComponent.h"
#include "Player2InputComponent.h"
#include "PlayerGraphicsComponent.h"
#include <SDL.h>

void ButtonInputComponent::update(GameObject * gameObject)
{
	SDL_PumpEvents();
	int x, y;
	if (SDL_GetMouseState(&x, &y) && SDL_BUTTON(SDL_BUTTON_LEFT) &&
		x > gameObject->getGraphicsComponent()->getdRect()->x && 
		x < ((gameObject->getGraphicsComponent()->getdRect()->x) + (gameObject->getGraphicsComponent()->getdRect()->w)) &&
		y > gameObject->getGraphicsComponent()->getdRect()->y &&
		y < ((gameObject->getGraphicsComponent()->getdRect()->y) + (gameObject->getGraphicsComponent()->getdRect()->h)))
	{
		SDL_Log("Mouse Button 1 (left) is pressed at ");
		SDL_Log(std::to_string(x).c_str());
		SDL_Log(std::to_string(y).c_str());
		clicked();
	}

	int flip = 1;

	if (gameObject->getGraphicsComponent()->getdRect()->h > 600)
	{
		flip = flip * (-1);
	}
	gameObject->getGraphicsComponent()->getdRect()->h += flip;
}

void ButtonInputComponent::clicked()
{
	//Create play scene
	Scene * play = new Scene;

	//Create player 1 (WASD)
	GameObject* player = new GameObject(new PlayerGraphicsComponent("47444.png", { 6, 21,  33, 16 }, { SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 32 * 4, 16 * 4 }),
		new PlayerInputComponent());
	play->add(player);


	//Create player 2 (ARROWS)
	GameObject* player2 = new GameObject(new PlayerGraphicsComponent("47444.png", { 6, 21, 33, 16 }, { 100 , 100, 32 * 4, 16 * 4 }),
		new Player2InputComponent());
	play->add(player2);

	//Load sounds 
	Audio* audio = Locator::getAudio();
	audio->addSound("slimeball.wav");
	audio->addSound("iceball.wav");

	play->run();
}
