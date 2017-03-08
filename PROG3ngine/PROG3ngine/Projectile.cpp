#include "Projectile.h"



Projectile::Projectile(PositionComponent* position, GraphicsComponent* graphics) : GameObject (position, graphics)
{
	xVel = 2000;
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
