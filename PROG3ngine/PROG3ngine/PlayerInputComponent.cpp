#include "PlayerInputComponent.h"
#include "Audio.h"
#include "Locator.h"
#include "System.h"
#include "Projectile.h"

static Uint32 lastShot = 0;

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
		if (SDL_GetTicks() > lastShot + 500)
		{
			//Add projectile to scene
			gameObject->getScene()->add(new Projectile(new PositionComponent(gameObject->getPositionComponent()->getX() + gameObject->getGraphicsComponent()->getdRect()->w, gameObject->getPositionComponent()->getY() + gameObject->getGraphicsComponent()->getdRect()->h / 2), new GraphicsComponent("laserBlue01.png", { 0,0,54,9 }, { 0, 0, 54, 9 })));
			lastShot = SDL_GetTicks();

			//Play sound
			Audio* audio = Locator::getAudio();
			audio->playSound(0);
		}
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



