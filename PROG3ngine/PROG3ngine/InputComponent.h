#pragma once
#include "GameObject.h"

class GameObject;

class InputComponent
{
public:
	virtual void update(GameObject& gameObject) = 0;
};

