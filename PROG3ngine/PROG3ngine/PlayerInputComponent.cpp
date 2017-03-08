#include "PlayerInputComponent.h"
#include "Audio.h"
#include "Locator.h"
#include "System.h"
#include "Projectile.h"
#include <SDL.h>
#include <thread>

static Uint32 lastShot = 0;

void PlayerInputComponent::update(GameObject& gameObject)
{
		SDL_PumpEvents();
	if (state[SDL_SCANCODE_W])
	{
		gameObject.yVel -= PLAYER_ACC;
	}
	if (state[SDL_SCANCODE_S])
	{
		gameObject.yVel += PLAYER_ACC;
	}
	if (state[SDL_SCANCODE_D])
	{
		gameObject.xVel += PLAYER_ACC;
	}
	if (state[SDL_SCANCODE_A])
	{
		gameObject.xVel -= PLAYER_ACC;
	}
	if (state[SDL_SCANCODE_SPACE])
	{
		if (SDL_GetTicks() > lastShot + 500)
		{
			//Add projectile to scene
			gameObject.getScene()->add(new Projectile(new PositionComponent(gameObject.getPositionComponent()->getX() + gameObject.getGraphicsComponent()->getdRect().w, gameObject.getPositionComponent()->getY() + gameObject.getGraphicsComponent()->getdRect().h / 2), new GraphicsComponent(std::string("laserBlue01.png"), SDL_Rect({ 0, 0, 54, 9 }), SDL_Rect({ 0, 0, 54, 9 }))));
			lastShot = SDL_GetTicks();

			//Play sound
			Audio* audio = Locator::getAudio();
			audio->playSound(0);
		}
	}

	//Cap player speed
	if (gameObject.yVel > PLAYER_SPEED)
	{
		gameObject.yVel = PLAYER_SPEED;
	}
	if (gameObject.yVel < -PLAYER_SPEED)
	{
		gameObject.yVel = -PLAYER_SPEED;
	}
	if (gameObject.xVel > PLAYER_SPEED) 
	{
		gameObject.xVel = PLAYER_SPEED;
	}
	if (gameObject.xVel < -PLAYER_SPEED)
	{
		gameObject.xVel = -PLAYER_SPEED;
	}

	//Friction

	gameObject.xVel *= 0.98f;
	gameObject.yVel *= 0.98f;

	//Keep player on screen
	if (gameObject.getPositionComponent()->getX() < 0)
	{
		gameObject.getPositionComponent()->setX(0);
	}
	if (gameObject.getPositionComponent()->getX() > SCREEN_WIDTH - (gameObject.getGraphicsComponent()->getdRect().w))
	{
		gameObject.getPositionComponent()->setX(SCREEN_WIDTH - (gameObject.getGraphicsComponent()->getdRect().w));
	}

	//Keep player on screen
	if (gameObject.getPositionComponent()->getY() < 0)
	{
		gameObject.getPositionComponent()->setY(0);
	}
	if (gameObject.getPositionComponent()->getY() > SCREEN_HEIGHT - (gameObject.getGraphicsComponent()->getdRect().h))
	{
		gameObject.getPositionComponent()->setY(SCREEN_HEIGHT - (gameObject.getGraphicsComponent()->getdRect().h));
	}
}