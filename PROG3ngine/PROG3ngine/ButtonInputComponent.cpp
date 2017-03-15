#include "ButtonInputComponent.h"
#include <string>
#include "Locator.h"
#include "PlayerInputComponent.h"
#include "Player2InputComponent.h"
#include "PlayerGraphicsComponent.h"
#include <SDL.h>
#include "PlayScene.h"
#include "Level.h"

void ButtonInputComponent::update(GameObject& gameObject)
{
	SDL_PumpEvents();
	int x, y;
	if (SDL_GetMouseState(&x, &y) && SDL_BUTTON(SDL_BUTTON_LEFT) &&
		x > gameObject.getGraphicsComponent()->getdRect().x && 
		x < ((gameObject.getGraphicsComponent()->getdRect().x) + (gameObject.getGraphicsComponent()->getdRect().w)) &&
		y > gameObject.getGraphicsComponent()->getdRect().y &&
		y < ((gameObject.getGraphicsComponent()->getdRect().y) + (gameObject.getGraphicsComponent()->getdRect().h)))
	{
		SDL_Log("Mouse Button 1 (left) is pressed at ");
		SDL_Log(std::to_string(x).c_str());
		SDL_Log(std::to_string(y).c_str());
		clicked();
	}
}

void ButtonInputComponent::clicked()
{
	PlayScene* play = new PlayScene();
}
