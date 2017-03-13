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
	dRect = { 0, 0, sRect.w, sRect.h};
}

GraphicsComponent::GraphicsComponent(std::string path, int scale)
{
	int w, h;
	spriteTexture = IMG_LoadTexture(sys.getRenderer(), path.c_str());
	SDL_QueryTexture(spriteTexture, NULL, NULL, &w, &h);
	SDL_SetTextureBlendMode(spriteTexture, SDL_BLENDMODE_BLEND);
	sRect = { 0, 0, w, h };
	dRect = { 0, 0, sRect.w * scale, sRect.h * scale };
}

//Path to file, Source Rect, Destination Rect
GraphicsComponent::GraphicsComponent(std::string path, SDL_Rect s, int scale) : sRect(s)
{
	spriteTexture = IMG_LoadTexture(sys.getRenderer(), path.c_str());
	SDL_SetTextureBlendMode(spriteTexture, SDL_BLENDMODE_BLEND);
	dRect = { 0, 0, s.w * scale, s.h * scale };
}

//Path to file, Source Rect, Destination Rect
GraphicsComponent::GraphicsComponent(std::string path, SDL_Rect s) : sRect(s)
{
	spriteTexture = IMG_LoadTexture(sys.getRenderer(), path.c_str());
	SDL_SetTextureBlendMode(spriteTexture, SDL_BLENDMODE_BLEND);
	dRect = { 0, 0, s.w, s.h };
}

void GraphicsComponent::update(GameObject& gameObject)
{
	if (gameObject.getPositionComponent() != nullptr)
	{
		dRect = { (int)gameObject.getPositionComponent()->getX(), (int)gameObject.getPositionComponent()->getY(), dRect.w, dRect.h };
	}
	SDL_RenderCopy(sys.getRenderer(), spriteTexture, &sRect, &dRect);
	if (DEBUG)
	{
		if (gameObject.getPhysicsComponent() != nullptr)
		{
			SDL_SetRenderDrawColor(sys.getRenderer(), 255, 0, 0, 0);
			SDL_RenderDrawRect(sys.getRenderer(), &gameObject.getPhysicsComponent()->getHitBox());
		}
	}
}

SDL_Rect &GraphicsComponent::getdRect()
{
	return dRect;
}

GraphicsComponent::~GraphicsComponent()
{
	SDL_DestroyTexture(spriteTexture);
}
