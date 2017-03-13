#pragma once
#include "GraphicsComponent.h"
#include <string>

class PlayerGraphicsComponent :
	public GraphicsComponent
{
public:
	PlayerGraphicsComponent(std::string path, SDL_Rect s, int scale);
	void update(GameObject& gameObject) override;
};

