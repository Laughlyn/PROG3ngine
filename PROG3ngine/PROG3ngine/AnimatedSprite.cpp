#include "AnimatedSprite.h"

AnimatedSprite* AnimatedSprite::getInstance(const SDL_Rect& r, std::string t)
{
	return new AnimatedSprite(r, t);
}

AnimatedSprite* AnimatedSprite::getInstance(const SDL_Rect& r, std::string t, SDL_Rect sC)
{
	return new AnimatedSprite(r, t, sC);
}

AnimatedSprite::AnimatedSprite(const SDL_Rect& r, std::string t) : Sprite(r, t)
{

}

AnimatedSprite::AnimatedSprite(const SDL_Rect& r, std::string t, SDL_Rect sC) : Sprite(r, t)
{
	SDL_Rect myClip = sC;
}

void AnimatedSprite::update(float timeStep)
{

}

void AnimatedSprite::draw()
{
	/*myClip.x = 7;
	myClip.y = 102;
	myClip.w = 26;
	myClip.h = 12;*/


	currentClip = myClip;
	SDL_RenderCopy(sys.getRenderer(), getTexture(), &currentClip, &getRect());
}

AnimatedSprite::~AnimatedSprite()
{

}
