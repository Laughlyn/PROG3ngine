#pragma once
#include "GameObject.h"
class Projectile :
	public GameObject
{
public:
	Projectile(PositionComponent* position, GraphicsComponent* graphics);
	void scripts();
	~Projectile();
};

