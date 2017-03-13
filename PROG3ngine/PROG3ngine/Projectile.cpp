#include "Projectile.h"



Projectile::Projectile(PositionComponent* position = nullptr, MovementComponent* movement = nullptr, GraphicsComponent* graphics = nullptr, PhysicsComponent* physics = nullptr) : GameObject (position, movement, graphics, physics)
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
