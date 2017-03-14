#include "PhysicsComponent.h"
#include "Explosion.h"

class GameObject;

PhysicsComponent::PhysicsComponent(SDL_Rect hB, int b, int f, int m) : hitBox(hB), bounce(b), friction(f), mass(m)
{
	offX = hB.x;
	offY = hB.y;
}

void PhysicsComponent::update(GameObject& gameObject, float timeStep)
{
	gameObject.getPositionComponent()->setY(gameObject.getPositionComponent()->getY() + 400 * timeStep * mass);

	hitBox = {(int)gameObject.getPositionComponent()->getX() + offX, (int)gameObject.getPositionComponent()->getY() + offY, hitBox.w, hitBox.h};
}

void PhysicsComponent::collision(std::unique_ptr<GameObject> gO, std::unique_ptr<GameObject> otherGO)
{
	gO->expire();
	//Add projectile to scene
	gO->getScene()->add(
		std::make_unique<Explosion>(
			std::make_unique<PositionComponent>(gO->getPositionComponent()->getX() + gO->getGraphicsComponent()->getdRect().w, gO->getPositionComponent()->getY() + gO->getGraphicsComponent()->getdRect().h / 2),
			std::make_shared<GraphicsComponent>(std::string("47444.png"), SDL_Rect({ 249, 125, 14, 14 }), 4)));
}

SDL_Rect PhysicsComponent::getHitBox()
{
	return hitBox;
}