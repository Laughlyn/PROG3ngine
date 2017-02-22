#include "GraphicsComponent.h"
#include <SDL.h>
#include <SDL_image.h>

GraphicsComponent::GraphicsComponent(std::string path)
{
	spriteTexture = IMG_LoadTexture(sys.getRenderer(), path.c_str());
	SDL_SetTextureBlendMode(spriteTexture, SDL_BLENDMODE_BLEND);
}

GraphicsComponent::GraphicsComponent(std::string path, SDL_Rect s, SDL_Rect d) : sRect(s), dRect(d)
{
	spriteTexture = IMG_LoadTexture(sys.getRenderer(), path.c_str());
	SDL_SetTextureBlendMode(spriteTexture, SDL_BLENDMODE_BLEND);
}

void GraphicsComponent::update(GameObject* gameObject)
{
	SDL_RenderCopy(sys.getRenderer(), spriteTexture, &sRect, &dRect);
}

SDL_Rect* GraphicsComponent::getdRect()
{
	return &dRect;
}

GraphicsComponent::~GraphicsComponent()
{
}
