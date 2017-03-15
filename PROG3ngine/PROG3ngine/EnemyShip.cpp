#include "EnemyShip.h"

EnemyShip::EnemyShip(PositionComponent* position, MovementComponent* movement, GraphicsComponent* graphics, PhysicsComponent* physics) : GameObject(position, movement, graphics, physics)
{

}

void EnemyShip::scripts()
{
	if (getPositionComponent()->getX() < SCREEN_WIDTH / 2)
	{
		getMovementComponent()->setXVel(-300);
		getMovementComponent()->setYVel(100);
	}
}

void EnemyShip::onExpiration()
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
}