#include "Sprite.h"
#include <SDL_image.h>
#include "System.h"

Sprite* Sprite::getInstance(const SDL_Rect& r, std::string t)
{
	return new Sprite(r, t);
}

Sprite::Sprite(const SDL_Rect& r, std::string t):GameObject(r), path(t)
{
	spriteTexture = IMG_LoadTexture(sys.getRenderer(), path.c_str());
}

void Sprite::draw()
{
	SDL_RenderCopy(sys.getRenderer(), spriteTexture, NULL, &getRect());
}

Sprite::~Sprite()
{
	SDL_DestroyTexture(spriteTexture);
}
