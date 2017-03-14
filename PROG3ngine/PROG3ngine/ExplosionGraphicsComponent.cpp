#include "ExplosionGraphicsComponent.h"

Uint32 timer = SDL_GetTicks();

void ExplosionGraphicsComponent::update(GameObject& gameObject)
{
	if (SDL_GetTicks() - timer > 3000)
	{
		sRect = { 6 + 33 * 4, 21, 33, 16 };
	}

	dRect = { (int)gameObject.getPositionComponent()->getX(), (int)gameObject.getPositionComponent()->getY(), dRect.w, dRect.h };

	//Render
	SDL_RenderCopy(sys.getRenderer(), spriteTexture, &sRect, &dRect);
}