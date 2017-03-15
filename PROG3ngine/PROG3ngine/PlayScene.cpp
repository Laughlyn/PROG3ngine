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
#include "EnemyShip.h"
#include <random>

Uint32 waveTime = -10000;
Uint32 starTime = 0;

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

	srand(SDL_GetTicks());
	
	std::string filePath = "47444.png";
	textureAtlas = IMG_LoadTexture(sys.getRenderer(), filePath.c_str());

	//Create player 1 (WASD)
	GameObject* player = new GameObject(
		new PositionComponent(200, 300),
		new MovementComponent(),
		new PlayerGraphicsComponent(textureAtlas, SDL_Rect({ 6, 21,  33, 16 }), 4),
		new PlayerInputComponent(),
		new PhysicsComponent({ 10, 10, 32 * 4 - 20, 16 * 4 - 20 }, 0 , 0, 0));
	add(player);

	

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
		EnemyShip* enemy = new EnemyShip(
			new PositionComponent((float)1600 + 100 * i, (float)200 + 200 * i),
			new MovementComponent(-300, -100),
			new GraphicsComponent(textureAtlas, SDL_Rect({ 8, 106,  16, 16 }), 4),
			new PhysicsComponent({ 0, 0, 16 * 4, 16 * 4 }, 0, 0, 0));
		add(enemy);
	}
}

void PlayScene::createStars()
{
	std::string starPath = "star.png";
	SDL_Texture* texturePtr = IMG_LoadTexture(sys.getRenderer(), starPath.c_str());
	for (int i = 0; i < 5; i++)
	{
		GameObject* starGO = new GameObject(
			new PositionComponent((float)SCREEN_WIDTH + (rand() % 500), (float)(rand() % SCREEN_HEIGHT)),
			new MovementComponent(-200, 0),
			new GraphicsComponent(texturePtr, SDL_Rect({ 0, 0,  2, 2 }), 1));
		add(starGO);
	}
	GraphicsComponent* star2 = new GraphicsComponent(std::string("star.png"), SDL_Rect({ 0, 0,  2, 2 }), 1);
	for (int i = 0; i < 5; i++)
	{
		GameObject* starGO2 = new GameObject(
			new PositionComponent((float)SCREEN_WIDTH + (rand() % 500), (float)(rand() % SCREEN_HEIGHT)),
			new MovementComponent(-300, 0),
			star2);
		add(starGO2);
	}
}

void PlayScene::scripts()
{
	if (SDL_GetTicks() > waveTime + 10000)
	{
		createWave(5);
		waveTime = SDL_GetTicks();
	}
	if (SDL_GetTicks() > starTime + 500)
	{
		createStars();
		starTime = SDL_GetTicks();
	}
}