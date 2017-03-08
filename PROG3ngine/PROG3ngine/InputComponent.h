#pragma once
#include "GameObject.h"

class GameObject;

class InputComponent
{
public:
	virtual ~InputComponent();
	virtual void update(GameObject& gameObject) = 0;
};

