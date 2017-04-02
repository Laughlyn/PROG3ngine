#pragma once
#include "GameObject.h"
class EnemyShip :
	public GameObject
{
public:
	EnemyShip(PositionComponent* position, MovementComponent* movement, GraphicsComponent* graphics, PhysicsComponent* physics);
	EnemyShip(PositionComponent* position, MovementComponent* movement, GraphicsComponent* graphics, InputComponent* input, PhysicsComponent* physics);
	void scripts() override;
	void onExpiration() override;
};

