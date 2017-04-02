#include "ButtonInputComponent.h"
#include <string>
#include "Locator.h"
#include "PlayerInputComponent.h"
#include "Player2InputComponent.h"
#include "PlayerGraphicsComponent.h"
#include <SDL.h>
#include "PlayScene.h"
#include "Level.h"
#include "Utils.h"

void ButtonInputComponent::update(GameObject& gameObject, float timeStep)
{
	static float flip = 25;
	SDL_PumpEvents();
	if (pointRectCollision(x, y, gameObject.getGraphicsComponent()->getdRect()))
	{
		if (gameObject.getPositionComponent()->getAngle() <= -1 || gameObject.getPositionComponent()->getAngle() >= 1)
			flip *= -1;
		gameObject.getPositionComponent()->setAngle(gameObject.getPositionComponent()->getAngle() + flip * timeStep);
	}
	if (SDL_GetMouseState(&x, &y) & SDL_BUTTON_LMASK && pointRectCollision(x, y, gameObject.getGraphicsComponent()->getdRect()))
		//x > gameObject.getGraphicsComponent()->getdRect().x && 
		//x < ((gameObject.getGraphicsComponent()->getdRect().x) + (gameObject.getGraphicsComponent()->getdRect().w)) &&
		//y > gameObject.getGraphicsComponent()->getdRect().y &&
		//y < ((gameObject.getGraphicsComponent()->getdRect().y) + (gameObject.getGraphicsComponent()->getdRect().h)))
	{
		SDL_Log("Mouse Button 1 (left) is pressed at ");
		SDL_Log(std::to_string(x).c_str());
		SDL_Log(std::to_string(y).c_str());
		clicked();
	}
}

void ButtonInputComponent::clicked()
{
	new PlayScene();
}