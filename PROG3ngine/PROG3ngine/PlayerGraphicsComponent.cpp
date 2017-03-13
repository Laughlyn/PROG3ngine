#include "PlayerGraphicsComponent.h"
#include "Constants.h"
#include "MovementComponent.h"

PlayerGraphicsComponent::PlayerGraphicsComponent(std::string path, SDL_Rect s, int scale) : GraphicsComponent(path, s, scale)
{

}

void PlayerGraphicsComponent::update(GameObject& gameObject)
{
	//Change sprite if ship is travelling fast enough up or down
	if (gameObject.getMovementComponent()->getYVel() > TILT_THRESH)
	{
		sRect = { 6 + 33 * 4, 21, 33, 16 };
	}
	if (gameObject.getMovementComponent()->getYVel() < -TILT_THRESH)
	{
		sRect = { 6 + 33 * 2, 21, 33, 16 };
	}
	if (gameObject.getMovementComponent()->getYVel() > -TILT_THRESH && gameObject.getMovementComponent()->getYVel() < TILT_THRESH)
	{
		sRect = { 6, 21, 33, 16 };
	}

	dRect = { (int)gameObject.getPositionComponent()->getX(), (int)gameObject.getPositionComponent()->getY(), dRect.w, dRect.h };

	//Render
	SDL_RenderCopy(sys.getRenderer(), spriteTexture, &sRect, &dRect);

	//Draw hitbox if in DEBUG mode
	if (DEBUG)
	{
		if (gameObject.getPhysicsComponent() != nullptr)
			SDL_SetRenderDrawColor(sys.getRenderer(), 255, 0, 0, 0);
		SDL_RenderDrawRect(sys.getRenderer(), &gameObject.getPhysicsComponent()->getHitBox());
	}
}
