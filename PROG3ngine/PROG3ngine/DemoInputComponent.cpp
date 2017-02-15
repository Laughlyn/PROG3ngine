#include "DemoInputComponent.h"
#include "Constants.h"

void DemoInputComponent::update(GameObject* gameObject)
{
	if (gameObject->x > SCREEN_WIDTH|| gameObject->x < 0)
	{
		gameObject->xVel *= -1;
	}

	if (gameObject->y > SCREEN_HEIGHT || gameObject->y < 0)
	{
		gameObject->yVel *= -1;
	}
}
