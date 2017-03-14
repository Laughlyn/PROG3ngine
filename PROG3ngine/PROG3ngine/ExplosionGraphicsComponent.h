#pragma once
#include "GraphicsComponent.h"
class ExplosionGraphicsComponent :
	public GraphicsComponent
{
private:
	virtual void update(GameObject& gameObject);
};

