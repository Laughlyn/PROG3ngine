#include "PlayerGraphicsComponent.h"

PlayerGraphicsComponent::PlayerGraphicsComponent(std::string path, SDL_Rect s, SDL_Rect d) : GraphicsComponent(path, s, d)
{

}

void PlayerGraphicsComponent::update(GameObject * gameObject)
{
	if (gameObject->yVel > TILT_THRESH)
	{
		sRect = { 6 + 6 + 32 * 4, 21, 32, 16 };
	}
	if (gameObject->yVel < -TILT_THRESH)
	{
		sRect = { 6 + 32 * 2, 21, 32, 16 };
	}
	if (gameObject->yVel > -TILT_THRESH && gameObject->yVel < TILT_THRESH)
	{
		sRect = { 6 , 21, 32, 16 };
	}
	dRect = { (int)gameObject->x, (int)gameObject->y, 32 * 4, 16 * 4 };
	SDL_RenderCopy(sys.getRenderer(), spriteTexture, &sRect, &dRect);
}
