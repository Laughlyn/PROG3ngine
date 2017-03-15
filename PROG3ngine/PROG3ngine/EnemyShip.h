#pragma once
#include "GameObject.h"
class EnemyShip :
	public GameObject
{
public:
	EnemyShip(PositionComponent* position, MovementComponent* movement, GraphicsComponent* graphics, PhysicsComponent* physics);
	void scripts() override;
	void onExpiration() override;
};

