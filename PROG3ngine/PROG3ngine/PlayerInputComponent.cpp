#include "PlayerInputComponent.h"
#include "Audio.h"
#include "Locator.h"
#include "System.h"
#include "Projectile.h"
#include <SDL.h>
#include <thread>
#include "MovementComponent.h"

static Uint32 lastShot = 0;

void PlayerInputComponent::update(GameObject& gameObject)
{
		SDL_PumpEvents();
	if (state[SDL_SCANCODE_W])
	{
		gameObject.getMovementComponent()->setYVel(gameObject.getMovementComponent()->getYVel() - PLAYER_ACC);
	}
	if (state[SDL_SCANCODE_S])
	{
		gameObject.getMovementComponent()->setYVel(gameObject.getMovementComponent()->getYVel() + PLAYER_ACC);
	}
	if (state[SDL_SCANCODE_D])
	{
		gameObject.getMovementComponent()->setXVel(gameObject.getMovementComponent()->getXVel() + PLAYER_ACC);
	}
	if (state[SDL_SCANCODE_A])
	{
		gameObject.getMovementComponent()->setXVel(gameObject.getMovementComponent()->getXVel() - PLAYER_ACC);
	}
	if (state[SDL_SCANCODE_SPACE])
	{
		if (SDL_GetTicks() > lastShot + 500)
		{
			//Add projectile to scene
			gameObject.getScene()->add(
				new Projectile(
				new PositionComponent(gameObject.getPositionComponent()->getX() + gameObject.getGraphicsComponent()->getdRect().w, gameObject.getPositionComponent()->getY() + gameObject.getGraphicsComponent()->getdRect().h / 2), 
				new MovementComponent(3000, 0),
				new GraphicsComponent(std::string("laserBlue01.png"), SDL_Rect({ 0, 0, 54, 9 }), 1),
				new PhysicsComponent({30, 0, 20, 9}, 1, 1, 0)));
			lastShot = SDL_GetTicks();

			//Play sound
			Audio* audio = Locator::getAudio();
			audio->playSound(0);
		}
	}

	//Cap player speed
	if (gameObject.getMovementComponent()->getYVel() > PLAYER_SPEED)
	{
		gameObject.getMovementComponent()->setYVel(PLAYER_SPEED);
	}
	if (gameObject.getMovementComponent()->getYVel() < -PLAYER_SPEED)
	{
		gameObject.getMovementComponent()->setYVel(-PLAYER_SPEED);
	}
	if (gameObject.getMovementComponent()->getXVel() > PLAYER_SPEED)
	{
		gameObject.getMovementComponent()->setXVel(PLAYER_SPEED);
	}
	if (gameObject.getMovementComponent()->getXVel() < -PLAYER_SPEED)
	{
		gameObject.getMovementComponent()->setXVel(-PLAYER_SPEED);
	}

	//Friction

	gameObject.getMovementComponent()->setXVel(gameObject.getMovementComponent()->getXVel() * 0.98f);
	gameObject.getMovementComponent()->setYVel(gameObject.getMovementComponent()->getYVel() * 0.98f);

	//Keep player on screen
	if (gameObject.getPositionComponent()->getX() < 0)
	{
		gameObject.getPositionComponent()->setX(0);
	}
	if (gameObject.getPositionComponent()->getX() > SCREEN_WIDTH - (gameObject.getGraphicsComponent()->getdRect().w))
	{
		gameObject.getPositionComponent()->setX((float)(SCREEN_WIDTH - (gameObject.getGraphicsComponent()->getdRect().w)));
	}

	//Keep player on screen
	if (gameObject.getPositionComponent()->getY() < 0)
	{
		gameObject.getPositionComponent()->setY(0);
	}
	if (gameObject.getPositionComponent()->getY() > SCREEN_HEIGHT - (gameObject.getGraphicsComponent()->getdRect().h))
	{
		gameObject.getPositionComponent()->setY((float)(SCREEN_HEIGHT - (gameObject.getGraphicsComponent()->getdRect().h)));
	}
}