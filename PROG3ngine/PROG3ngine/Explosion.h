#pragma once
#include "GameObject.h"
class Explosion :
	public GameObject
{
public:
	Explosion(std::unique_ptr<PositionComponent> position, std::shared_ptr<GraphicsComponent>);
	~Explosion();
private:
	void scripts() override;
	Uint32 timer = SDL_GetTicks() + 3000;
};

