#pragma once
#include "Sprite.h"
#include <vector>
#include "System.h"

class AnimatedSprite :
	public Sprite
{
public:
	static AnimatedSprite* getInstance(const SDL_Rect&, std::string);
	static AnimatedSprite* getInstance(const SDL_Rect&, std::string, SDL_Rect);
	void update(float timeStep);
	void draw();
	~AnimatedSprite();
private:
	AnimatedSprite(const SDL_Rect&, std::string);
	AnimatedSprite(const SDL_Rect&, std::string, SDL_Rect);
	SDL_Rect myClip = { 0,0,0,0 };
	SDL_Rect currentClip = { 0,0,0,0 };
};

