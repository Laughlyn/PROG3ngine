#include "Level.h"
#include "GameObject.h"
#include "PlayerGraphicsComponent.h"
#include "PlayerInputComponent.h"
#include "Scene.h"
#include "Audio.h"
#include "Locator.h"

Level::Level(Scene* newScene) : scene(newScene)
{
	init();
}

void Level::init()
{
	std::string filePath = "47444.png";
	SDL_Texture* texturePtr = IMG_LoadTexture(sys.getRenderer(), filePath.c_str());
	textures.emplace_back(texturePtr);

	//Create player 1 (WASD)
	GameObject* player = new GameObject(
		new PositionComponent(200, 300),
		new MovementComponent(),
		new PlayerGraphicsComponent(textures[0], { 6, 21,  33, 16 }, 4),
		new PlayerInputComponent(),
		new PhysicsComponent(SDL_Rect({ 10, 10, 32 * 4 - 20, 16 * 4 - 20 }), 0, 0, 0));
	scene->add(player);
}

Level::~Level()
{
}
