#include "DynamicSprite.h"
#include "Constants.h"
#include "Sprite.h"
#include "System.h"

DynamicSprite* DynamicSprite::getInstance(const SDL_Rect& r, std::string t)
{
	return new DynamicSprite(r, t);
}

DynamicSprite::DynamicSprite(const SDL_Rect& r, std::string t) : Sprite(r,t)
{
	posX = (float)rect.x;
	posY = (float)rect.y;
}

void DynamicSprite::draw()
{
	SDL_RenderCopy(sys.getRenderer(), getTexture() , NULL, &getRect());
}

void DynamicSprite::tick(float timeStep)
{
	dirVectX = cos(radians);
	dirVectY = sin(radians);

	velY += 1000 * timeStep;

	velX += accelX * timeStep;
	velY += accelY * timeStep;

	//Move
	posX += velX * timeStep;
	rect.x = int(posX);

	posY += velY * timeStep;
	rect.y = int(posY);

	//Friction
	velX *= 0.99f;
	velY *= 0.99f;

	//Bounds
	if (radians > PI)
	{
		radians = -PI;
	}
	else if (radians < -PI)
	{
		radians = PI;
	}
}

void DynamicSprite::mouseDown(const SDL_Event& event)
{

}

void DynamicSprite::mouseUp(const SDL_Event& event)
{

}