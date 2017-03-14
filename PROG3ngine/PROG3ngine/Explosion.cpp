#include "Explosion.h"



Explosion::Explosion(std::unique_ptr<PositionComponent> position, std::shared_ptr<GraphicsComponent> graphics) : GameObject(std::move(position), graphics)
{
}


Explosion::~Explosion()
{
}


void Explosion::scripts()
{
	if (timer < SDL_GetTicks())
		expire();
}