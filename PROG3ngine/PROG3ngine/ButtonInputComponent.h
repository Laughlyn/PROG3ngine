#ifndef BUTTONINPUTCOMPONENT_H
#define BUTTONINPUTCOMPONENT_H

#include "InputComponent.h"
class ButtonInputComponent :
	public InputComponent
{
public:
	virtual void update(GameObject& gameObject, float timeStep);
	virtual void clicked();
private:
	int x = 0;
	int y = 0;
};

#endif