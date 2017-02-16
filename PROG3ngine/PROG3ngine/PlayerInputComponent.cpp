#include "PlayerInputComponent.h"
#include "Audio.h"
#include "Locator.h"
#include "System.h"

void PlayerInputComponent::update(GameObject* gameObject)
{
		SDL_PumpEvents();
	if (state[SDL_SCANCODE_W])
	{
		gameObject->yVel -= PLAYER_ACC;
	}
	if (state[SDL_SCANCODE_S])
	{
		gameObject->yVel += PLAYER_ACC;
	}
	if (state[SDL_SCANCODE_D])
	{
		gameObject->xVel += PLAYER_ACC;
	}
	if (state[SDL_SCANCODE_A])
	{
		gameObject->xVel -= PLAYER_ACC;
	}
	if (state[SDL_SCANCODE_SPACE])
	{
		Audio* audio = Locator::getAudio();
		audio->playSound(0);
	}
	if (gameObject->yVel > PLAYER_SPEED)
	{
		gameObject->yVel = PLAYER_SPEED;
	}
	if (gameObject->yVel < -PLAYER_SPEED)
	{
		gameObject->yVel = -PLAYER_SPEED;
	}
	if (gameObject->xVel > PLAYER_SPEED) 
	{
		gameObject->xVel = PLAYER_SPEED;
	}
	if (gameObject->xVel < -PLAYER_SPEED)
	{
		gameObject->xVel = -PLAYER_SPEED;
	}
}