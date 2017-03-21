#include "GraphicsComponent.h"
#include <SDL.h>
#include <SDL_image.h>

//Path to file
GraphicsComponent::GraphicsComponent(std::string const & path)
{
	int w, h;
	spriteTexture = IMG_LoadTexture(sys.getRenderer(), path.c_str());
	SDL_QueryTexture(spriteTexture, NULL, NULL, &w, &h);
	SDL_SetTextureBlendMode(spriteTexture, SDL_BLENDMODE_BLEND);
	sRect = { 0, 0, w, h };
	dRect = { 0, 0, sRect.w, sRect.h};
}

GraphicsComponent::GraphicsComponent(std::string const & path, int scale)
{
	int w, h;
	spriteTexture = IMG_LoadTexture(sys.getRenderer(), path.c_str());
	SDL_QueryTexture(spriteTexture, NULL, NULL, &w, &h);
	SDL_SetTextureBlendMode(spriteTexture, SDL_BLENDMODE_BLEND);
	sRect = { 0, 0, w, h };
	dRect = { 0, 0, sRect.w * scale, sRect.h * scale };
}

//Path to file, Source Rect, Destination Rect, render scale
GraphicsComponent::GraphicsComponent(std::string const & path, SDL_Rect & s, int scale) : sRect(s)
{
	spriteTexture = IMG_LoadTexture(sys.getRenderer(), path.c_str());
	SDL_SetTextureBlendMode(spriteTexture, SDL_BLENDMODE_BLEND);
	dRect = { 0, 0, s.w * scale, s.h * scale };
}

//Path to file, Source Rect, Destination Rect
GraphicsComponent::GraphicsComponent(std::string const & path, SDL_Rect & s) : sRect(s)
{
	spriteTexture = IMG_LoadTexture(sys.getRenderer(), path.c_str());
	SDL_SetTextureBlendMode(spriteTexture, SDL_BLENDMODE_BLEND);
	dRect = { 0, 0, s.w, s.h };
}

GraphicsComponent::GraphicsComponent(std::string const & path, std::vector<SDL_Rect>& frames) : frameClips(frames)
{
	animated = true;
	timer = SDL_GetTicks();
	spriteTexture = IMG_LoadTexture(sys.getRenderer(), path.c_str());
	SDL_SetTextureBlendMode(spriteTexture, SDL_BLENDMODE_BLEND);
	sRect = frameClips[0];
	dRect = { 0, 0, frameClips[0].w, frameClips[0].h };
}

GraphicsComponent::GraphicsComponent(std::string const & path, std::vector<SDL_Rect> & frames, int newScale) : frameClips(frames), scale(newScale)
{
	animated = true;
	timer = SDL_GetTicks();
	spriteTexture = IMG_LoadTexture(sys.getRenderer(), path.c_str());
	SDL_SetTextureBlendMode(spriteTexture, SDL_BLENDMODE_BLEND);
	sRect = frameClips[0];
	dRect = { 0, 0, frameClips[0].w * scale, frameClips[0].h * scale };
}

GraphicsComponent::GraphicsComponent(std::string const & path, std::vector<SDL_Rect> & frames, bool loop) : frameClips(frames), loop(loop)
{
	animated = true;
	timer = SDL_GetTicks();
	spriteTexture = IMG_LoadTexture(sys.getRenderer(), path.c_str());
	SDL_SetTextureBlendMode(spriteTexture, SDL_BLENDMODE_BLEND);
	sRect = frameClips[0];
	dRect = { 0, 0, frameClips[0].w * scale, frameClips[0].h * scale };
}

GraphicsComponent::GraphicsComponent(std::string const & path, std::vector<SDL_Rect> & frames, int newScale, bool loop) : frameClips(frames), scale(newScale), loop(loop)
{
	animated = true;
	timer = SDL_GetTicks();
	spriteTexture = IMG_LoadTexture(sys.getRenderer(), path.c_str());
	SDL_SetTextureBlendMode(spriteTexture, SDL_BLENDMODE_BLEND);
	sRect = frameClips[0];
	dRect = { 0, 0, frameClips[0].w * scale, frameClips[0].h * scale };
}

GraphicsComponent::GraphicsComponent(SDL_Texture* texture) : spriteTexture(texture)
{
	sharingTexture = true;
	int w, h;
	SDL_QueryTexture(spriteTexture, NULL, NULL, &w, &h);
	SDL_SetTextureBlendMode(spriteTexture, SDL_BLENDMODE_BLEND);
	sRect = { 0, 0, w, h };
	dRect = { 0, 0, sRect.w, sRect.h };
}

GraphicsComponent::GraphicsComponent(SDL_Texture* texture, SDL_Rect s, int newScale) : spriteTexture(texture), sRect(s), scale(newScale)
{
	sharingTexture = true;
	SDL_SetTextureBlendMode(spriteTexture, SDL_BLENDMODE_BLEND);
	dRect = { 0, 0, s.w * scale, s.h * scale };
}

GraphicsComponent::GraphicsComponent(SDL_Texture* texture, std::vector<SDL_Rect> frames, int customScale) : spriteTexture(texture), frameClips(frames), scale(customScale)
{
	sharingTexture = true;
	animated = true;
	timer = SDL_GetTicks();
	SDL_SetTextureBlendMode(spriteTexture, SDL_BLENDMODE_BLEND);
	sRect = frameClips[0];
	dRect = { 0, 0, frameClips[0].w * scale, frameClips[0].h * scale };
}

void GraphicsComponent::update(GameObject & gameObject, float timeStep)
{
	if (gameObject.getPositionComponent() != nullptr)
	{
		dRect = { (int)gameObject.getPositionComponent()->getX(), (int)gameObject.getPositionComponent()->getY(), dRect.w, dRect.h };
	}

	if (animated)
	{

		if (SDL_GetTicks() - timer > 50)
		{
			currentFrame++;
			timer = SDL_GetTicks();
		}
		if ((currentFrame > ((int)frameClips.size() - 1)))
		{
			if (loop)
			{
				currentFrame = 0;
			}
			else
			{
				gameObject.expire();
			}
		}
		else
		{
			SDL_RenderCopy(sys.getRenderer(), spriteTexture, &frameClips[currentFrame], &dRect);
		}
	}
	else
	{
		//Render
		SDL_RenderCopy(sys.getRenderer(), spriteTexture, &sRect, &dRect);
	}
	if (DEBUG)
	{
		if (gameObject.getPhysicsComponent() != nullptr)
		{
			SDL_SetRenderDrawColor(sys.getRenderer(), 255, 0, 0, 0);
			SDL_RenderDrawRect(sys.getRenderer(), &gameObject.getPhysicsComponent()->getHitBox());
		}
	}
}

SDL_Texture*  GraphicsComponent::getTexture()
{
	return spriteTexture;
}

SDL_Rect & GraphicsComponent::getdRect()
{
	return dRect;
}

GraphicsComponent::~GraphicsComponent()
{
	if (!sharingTexture)
	{
		SDL_DestroyTexture(spriteTexture);
	}
}
