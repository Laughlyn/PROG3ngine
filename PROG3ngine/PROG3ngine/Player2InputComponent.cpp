#include "Player2InputComponent.h"
#include "Audio.h"
#include "Locator.h"
#include "System.h"

void Player2InputComponent::update(GameObject& gameObject)
{
	SDL_PumpEvents();
	/*if (state[SDL_SCANCODE_UP])
	{
		gameObject.yVel -= 50;
	}
	if (state[SDL_SCANCODE_DOWN])
	{
		gameObject.yVel += 50;
	}
	if (state[SDL_SCANCODE_RIGHT])
	{
		gameObject.xVel += 50;
	}
	if (state[SDL_SCANCODE_LEFT])
	{
		gameObject.xVel -= 50;
	}
	if (state[SDL_SCANCODE_RCTRL])
	{
		Audio* audio = Locator::getAudio();
		audio->playSound(1);
	}
	if (gameObject.yVel > 1000)
	{
		gameObject.yVel = 1000;
	}
	if (gameObject.yVel < -1000)
	{
		gameObject.yVel = -1000;
	}
	if (gameObject.xVel > 1000)
	{
		gameObject.xVel = 1000;
	}
	if (gameObject.xVel < -1000)
	{
		gameObject.xVel = -1000;
	}*/
}