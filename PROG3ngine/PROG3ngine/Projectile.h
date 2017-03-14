#pragma once
#include "GameObject.h"
class Projectile :
	public GameObject
{
public:
	Projectile(std::unique_ptr<PositionComponent> position, std::unique_ptr<MovementComponent> movement, std::shared_ptr<GraphicsComponent> graphics, std::unique_ptr<PhysicsComponent> physics);
	void scripts();
	~Projectile();
};