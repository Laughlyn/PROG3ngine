#pragma once
#include "GameObject.h"
class Projectile :
	public GameObject
{
public:
	Projectile(PositionComponent* position, MovementComponent* movement, GraphicsComponent* graphics, PhysicsComponent* physics);
	void scripts();
	~Projectile();
};