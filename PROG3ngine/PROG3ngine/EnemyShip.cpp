#include "EnemyShip.h"
#include "Audio.h"
#include "Locator.h"

EnemyShip::EnemyShip(PositionComponent* position, MovementComponent* movement, GraphicsComponent* graphics, PhysicsComponent* physics) : GameObject(position, movement, graphics, physics)
{

}

float angle = 0;

void EnemyShip::scripts()
{
	//Bob up and down
	getMovementComponent()->setYVel(std::sin(angle) * 250.f);
	angle += 0.005f;
}

void EnemyShip::onExpiration()
{
	if (getPositionComponent()->getX() > -50 && getPositionComponent()->getX() < SCREEN_WIDTH && getPositionComponent()->getY() > -50 && getPositionComponent()->getY() < SCREEN_HEIGHT)
	{
		SDL_Rect frame1 = { 109, 441, 32, 32 };
		SDL_Rect frame2 = { 145, 442, 32, 32 };
		SDL_Rect frame3 = { 178, 443, 30, 30 };
		std::vector<SDL_Rect> frameList;
		frameList.emplace_back(frame1);
		frameList.emplace_back(frame2);
		frameList.emplace_back(frame3);

		getScene()->add(
			new GameObject(
				getPositionComponent(),
				getMovementComponent(),
				new GraphicsComponent(getGraphicsComponent()->getTexture(), frameList, 2)));

		Audio* audio = Locator::getAudio();
		audio->playSound(EXPLODE);
	}
}