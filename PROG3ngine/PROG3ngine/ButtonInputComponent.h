#pragma once
#include "InputComponent.h"
class ButtonInputComponent :
	public InputComponent
{
public:
	virtual void update(GameObject& gameObject);
	virtual void clicked();
};

