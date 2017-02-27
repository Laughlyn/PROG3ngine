#include "Projectile.h"



Projectile::Projectile(PositionComponent* position, GraphicsComponent* graphics) : GameObject (position, graphics)
{
	xVel = 2000;
}

void Projectile::scripts()
{

}

Projectile::~Projectile()
{
}
