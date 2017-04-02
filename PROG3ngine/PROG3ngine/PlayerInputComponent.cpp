#include "PlayerInputComponent.h"
#include "Audio.h"
#include "Locator.h"
#include "System.h"
#include "Projectile.h"
#include <SDL.h>
#include <thread>
#include "MovementComponent.h"
#include "VectorMovementComponent.h"
#include "Utils.h"

static Uint32 lastShot = 0;

void PlayerInputComponent::update(GameObject& gameObject, float timeStep)
{
		SDL_PumpEvents();
	if (state[SDL_SCANCODE_W])
	{
		gameObject.getMovementComponent()->setYVel(gameObject.getMovementComponent()->getYVel() - PLAYER_ACC * timeStep);
	}
	if (state[SDL_SCANCODE_S])
	{
		gameObject.getMovementComponent()->setYVel(gameObject.getMovementComponent()->getYVel() + PLAYER_ACC * timeStep);
	}
	if (state[SDL_SCANCODE_D])
	{
		gameObject.getMovementComponent()->setXVel(gameObject.getMovementComponent()->getXVel() + PLAYER_ACC * timeStep);
	}
	if (state[SDL_SCANCODE_A])
	{
		gameObject.getMovementComponent()->setXVel(gameObject.getMovementComponent()->getXVel() - PLAYER_ACC * timeStep);
	}
	if (state[SDL_SCANCODE_SPACE])
	{
		if (SDL_GetTicks() > lastShot + FIRE_SPEED)
		{
			//Add projectile to scene
			gameObject.getScene()->add(
				new Projectile(
				new PositionComponent(gameObject.getPositionComponent()->getX() + gameObject.getGraphicsComponent()->getdRect().w, gameObject.getPositionComponent()->getY() + gameObject.getGraphicsComponent()->getdRect().h / 2), 
				new VectorMovementComponent(3000, PI/2),
				new GraphicsComponent(std::string("laserBlue01.png"), SDL_Rect({ 0, 0, 54, 9 }), 1),
				new PhysicsComponent(SDL_Rect({30, 0, 20, 9}), 1, 1, 0)));
			lastShot = SDL_GetTicks();

			//Play sound
			Audio* audio = Locator::getAudio();
			audio->playSound(LASER);
		}
	}
	if (state[SDL_SCANCODE_LCTRL])
	{
		if (SDL_GetTicks() > lastShot + FIRE_SPEED * 3)
		{
			//Add projectile to scene
			gameObject.getScene()->add(
				new Projectile(
					new PositionComponent(gameObject.getPositionComponent()->getX() + gameObject.getGraphicsComponent()->getdRect().w, gameObject.getPositionComponent()->getY() + gameObject.getGraphicsComponent()->getdRect().h / 2),
					new MovementComponent(1000, -1000),
					new GraphicsComponent(std::string("star2.png"), SDL_Rect({ 0, 0, 16, 16 }), 1),
					new PhysicsComponent(SDL_Rect({ 0, 0, 20, 9 }), 1, 1, 50)));
			lastShot = SDL_GetTicks();

			//Play sound
			Audio* audio = Locator::getAudio();
			audio->playSound(THWUMP);
		}
	}

	//Cap player speed
	gameObject.getMovementComponent()->setYVel(clamp(gameObject.getMovementComponent()->getYVel(), -PLAYER_SPEED, PLAYER_SPEED));

	gameObject.getMovementComponent()->setXVel(clamp(gameObject.getMovementComponent()->getXVel(), -PLAYER_SPEED, PLAYER_SPEED));


	/*if (gameObject.getMovementComponent()->getYVel() > PLAYER_SPEED)
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
	}*/

	//Friction, stops ship

	gameObject.getMovementComponent()->setXVel(gameObject.getMovementComponent()->getXVel() * 0.98f);
	gameObject.getMovementComponent()->setYVel(gameObject.getMovementComponent()->getYVel() * 0.98f);

	////Keep player on screen
	//if (gameObject.getPositionComponent()->getX() < 0)
	//{
	//	gameObject.getPositionComponent()->setX(0);
	//}
	//if (gameObject.getPositionComponent()->getX() > SCREEN_WIDTH - (gameObject.getGraphicsComponent()->getdRect().w))
	//{
	//	gameObject.getPositionComponent()->setX((float)(SCREEN_WIDTH - (gameObject.getGraphicsComponent()->getdRect().w)));
	//}

	////Keep player on screen
	//if (gameObject.getPositionComponent()->getY() < 0)
	//{
	//	gameObject.getPositionComponent()->setY(0);
	//}
	//if (gameObject.getPositionComponent()->getY() > SCREEN_HEIGHT - (gameObject.getGraphicsComponent()->getdRect().h))
	//{
	//	gameObject.getPositionComponent()->setY((float)(SCREEN_HEIGHT - (gameObject.getGraphicsComponent()->getdRect().h)));
	//}


	gameObject.getPositionComponent()->setY(clamp(gameObject.getPositionComponent()->getY(), 0.f, (float)SCREEN_HEIGHT - (gameObject.getGraphicsComponent()->getdRect().h)));

	gameObject.getPositionComponent()->setX(clamp(gameObject.getPositionComponent()->getX(), 0.f, (float)SCREEN_WIDTH - (gameObject.getGraphicsComponent()->getdRect().w)));

}