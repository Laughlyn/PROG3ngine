#include "PlayerInputComponent.h"
#include "Audio.h"
#include "Locator.h"
#include "System.h"

void PlayerInputComponent::update(GameObject* gameObject)
{
		SDL_PumpEvents();
	if (state[SDL_SCANCODE_W])
	{
		gameObject->yVel -= 50;
	}
	if (state[SDL_SCANCODE_S])
	{
		gameObject->yVel += 50;
	}
	if (state[SDL_SCANCODE_D])
	{
		gameObject->xVel += 50;
	}
	if (state[SDL_SCANCODE_A])
	{
		gameObject->xVel -= 50;
	}
	if (state[SDL_SCANCODE_SPACE])
	{
		Audio* audio = Locator::getAudio();
		audio->playSound(0);
	}
	if (gameObject->yVel > 1000)
	{
		gameObject->yVel = 1000;
	}
	if (gameObject->yVel < -1000)
	{
		gameObject->yVel = -1000;
	}
	if (gameObject->xVel > 1000)
	{
		gameObject->xVel = 1000;
	}
	if (gameObject->xVel < -1000)
	{
		gameObject->xVel = -1000;
	}
}