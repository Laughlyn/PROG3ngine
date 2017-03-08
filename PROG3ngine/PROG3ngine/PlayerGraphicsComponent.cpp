#include "PlayerGraphicsComponent.h"

PlayerGraphicsComponent::PlayerGraphicsComponent(std::string path, SDL_Rect s, SDL_Rect d) : GraphicsComponent(path, s, d)
{

}

void PlayerGraphicsComponent::update(GameObject& gameObject)
{
	if (gameObject.yVel > TILT_THRESH)
	{
		sRect = { 6 + 33 * 4, 21, 33, 16 };
	}
	if (gameObject.yVel < -TILT_THRESH)
	{
		sRect = { 6 + 33 * 2, 21, 33, 16 };
	}
	if (gameObject.yVel > -TILT_THRESH && gameObject.yVel < TILT_THRESH)
	{
		sRect = { 6, 21, 33, 16 };
	}
	dRect = { (int)gameObject.getPositionComponent()->getX(), (int)gameObject.getPositionComponent()->getY(), 32 * 4, 16 * 4 };
	SDL_RenderCopy(sys.getRenderer(), spriteTexture, &sRect, &dRect);
}
