#include "Projectile.h"



Projectile::Projectile(std::unique_ptr<PositionComponent> position, std::unique_ptr<MovementComponent> movement, std::shared_ptr<GraphicsComponent> graphics, std::unique_ptr<PhysicsComponent> physics) : GameObject (std::move(position), std::move(movement), graphics, std::move(physics))
{
}

void Projectile::scripts()
{
	if (getPositionComponent())
	{
		if (getPositionComponent()->getX() > SCREEN_WIDTH)
		{
			expire();
		}
	}
}

Projectile::~Projectile()
{
}
