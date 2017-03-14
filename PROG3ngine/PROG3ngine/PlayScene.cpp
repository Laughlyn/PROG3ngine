#include "PlayScene.h"
#include "PlayerGraphicsComponent.h"
#include "Player2InputComponent.h"
#include "Audio.h"
#include "Locator.h"
#include "PlayerInputComponent.h"
#include "InputComponent.h"
#include <string>
#include "PhysicsComponent.h"
#include "MovementComponent.h"
#include <random>
#include <memory>

Uint32 waveTime = -10000;

//Enemy
SDL_Rect clipRect = { 8, 106,  16, 16 };
std::shared_ptr<GraphicsComponent> enemyGC = std::make_shared<GraphicsComponent>(std::string("47444.png"), clipRect, 4);

//Background
//std::shared_ptr<GraphicsComponent> bG = std::make_shared<GraphicsComponent>(std::string("blue.png"));

PlayScene::PlayScene()
{
	//Create background
	/*int bGx = 0;
	int bGy = 0;
	SDL_Rect sRect{ 0, 0, 256, 256 };
	SDL_Rect dRect{ 0, 0, 256, 256 };
	for (int i = 0; i < 128; i++)
	{
		GameObject* background = new GameObject(
			std::make_unique<PositionComponent>(bGx, bGy),
			new MovementComponent(-100, 0),
			bG);
		add(background);
		bGx = 256 * i - (i / 8 * (256*8));
		bGy = 256 * (i / 8);
	}*/

	//Create player 1 (WASD)
	SDL_Rect clipRect = { 6, 21,  33, 16 };
	SDL_Rect hitBoxRect = { 10, 10, 32 * 4 - 20, 16 * 4 - 20 };
	std::unique_ptr<GameObject> player = std::make_unique<GameObject>(
		std::make_unique<PositionComponent>(200, 300),
		std::make_unique<MovementComponent>(),
		std::make_shared<PlayerGraphicsComponent>(std::string("47444.png"), clipRect, 4),
		std::make_unique<PlayerInputComponent>(),
		std::make_unique<PhysicsComponent>(hitBoxRect, 0 , 0, 0));
	add(std::move(player));

	//Create wave of enemies
	//createWave(5);

	//Load sounds 
	Audio* audio = Locator::getAudio();
	audio->addSound("slimeball.wav");
	audio->addSound("iceball.wav");

	run();
}

void PlayScene::createWave(int size)
{
	//Create wave of enemies
	SDL_Rect hitBoxRect = { 0, 0, 16 * 4, 16 * 4 };
	for (int i = 0; i < size; i++)
	{
		std::unique_ptr<GameObject> enemy = std::make_unique<GameObject>(
			std::make_unique<PositionComponent>((float)1600 + 100 * i, (float)200 + 200 * i),
			std::make_unique<MovementComponent>(-200, -40),
			enemyGC,
			std::make_unique<PhysicsComponent>(hitBoxRect, 0, 0, 0));
		add(std::move(enemy));
	}
}

void PlayScene::scripts()
{
	if (SDL_GetTicks() > waveTime + 10000)
	{
		createWave(5);
		waveTime = SDL_GetTicks();
	}
}

void scripts()
{

}