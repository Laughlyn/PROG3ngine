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

void DynamicSprite::update(float timeStep)
{
	move(timeStep);
}

void DynamicSprite::move(float timeStep)
{
	velX += accelX * timeStep;
	velY += accelY * timeStep;

	//Move
	posX += velX * timeStep;
	rect.x = int(posX);

	posY += velY * timeStep;
	rect.y = int(posY);
}

void DynamicSprite::mouseDown(const SDL_Event& event)
{

}

void DynamicSprite::mouseUp(const SDL_Event& event)
{

}