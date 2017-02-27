#include "GraphicsComponent.h"
#include <SDL.h>
#include <SDL_image.h>

//Path to file
GraphicsComponent::GraphicsComponent(std::string path)
{
	int w, h;
	spriteTexture = IMG_LoadTexture(sys.getRenderer(), path.c_str());
	SDL_QueryTexture(spriteTexture, NULL, NULL, &w, &h);
	SDL_SetTextureBlendMode(spriteTexture, SDL_BLENDMODE_BLEND);
	sRect = { 0, 0, w, h };
}

//Path to file, Source Rect, Destination Rect
GraphicsComponent::GraphicsComponent(std::string path, SDL_Rect s, SDL_Rect d) : sRect(s), dRect(d)
{
	spriteTexture = IMG_LoadTexture(sys.getRenderer(), path.c_str());
	SDL_SetTextureBlendMode(spriteTexture, SDL_BLENDMODE_BLEND);
}

void GraphicsComponent::update(GameObject* gameObject)
{
	if (gameObject->getPositionComponent())
	{
		dRect = { (int)gameObject->getPositionComponent()->getX(), (int)gameObject->getPositionComponent()->getY(), dRect.w, dRect.h };
	}
	SDL_RenderCopy(sys.getRenderer(), spriteTexture, &sRect, &dRect);
}

SDL_Rect* GraphicsComponent::getdRect()
{
	return &dRect;
}

GraphicsComponent::~GraphicsComponent()
{
}
