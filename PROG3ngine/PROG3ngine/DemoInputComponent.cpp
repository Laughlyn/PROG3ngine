#include "DemoInputComponent.h"
#include "Constants.h"

void DemoInputComponent::update(GameObject* gameObject)
{
	if (gameObject->getPositionComponent()->getX() > SCREEN_WIDTH|| gameObject->getPositionComponent()->getX() < 0)
	{
		gameObject->xVel *= -1;
	}

	if (gameObject->getPositionComponent()->getY() > SCREEN_HEIGHT || gameObject->getPositionComponent()->getY() < 0)
	{
		gameObject->yVel *= -1;
	}
}
