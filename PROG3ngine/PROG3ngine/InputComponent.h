#ifndef INPUTCOMPONENT_H
#define INPUTCOMPONENT_H

#include "GameObject.h"

class GameObject;

class InputComponent
{
public:
	virtual ~InputComponent();
	virtual void update(GameObject & gameObject, float timeStep) = 0;
};

#endif