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

Uint32 waveTime = -10000;

//Enemy
GraphicsComponent* enemyGC = new GraphicsComponent(std::string("47444.png"), { 8, 106,  16, 16 }, 4);

//Background
//GraphicsComponent* bG = new GraphicsComponent(std::string("blue.png"));

PlayScene::PlayScene()
{
	//Create background
	//int bGx = 0;
	//int bGy = 0;
	//SDL_Rect sRect{ 0, 0, 256, 256 };
	//SDL_Rect dRect{ 0, 0, 256, 256 };
	//for (int i = 0; i < 128; i++)
	//{
	//	GameObject* background = new GameObject(
	//		new PositionComponent(bGx, bGy),
	//		new MovementComponent(-100, 0),
	//		bG);
	//	add(background);
	//	bGx = 256 * i - (i / 8 * (256*8));
	//	bGy = 256 * (i / 8);
	//}

	//Create player 1 (WASD)
	GameObject* player = new GameObject(
		new PositionComponent(200, 300),
		new MovementComponent(),
		new PlayerGraphicsComponent(std::string("47444.png"), { 6, 21,  33, 16 }, 4),
		new PlayerInputComponent(),
		new PhysicsComponent({ 10, 10, 32 * 4 - 20, 16 * 4 - 20 }, 0 , 0, 0));
	add(player);

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
	for (int i = 0; i < size; i++)
	{
		GameObject* enemy = new GameObject(
			new PositionComponent((float)1600 + 100 * i, (float)200 + 200 * i),
			new MovementComponent(-200, -40),
			enemyGC,
			new PhysicsComponent({ 0, 0, 16 * 4, 16 * 4 }, 0, 0, 0));
		add(enemy);
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