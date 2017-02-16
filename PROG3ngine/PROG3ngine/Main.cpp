#include <SDL.h>
#include "Locator.h"
#include "Audio.h"
#include "System.h"
#include "Scene.h"
#include "GameObject.h"
#include "GraphicsComponent.h"
#include "PlayerInputComponent.h"
#include "Player2InputComponent.h"
#include "DemoInputComponent.h"

int main(int argc, char** argsv)
{
	Scene menu;
	Scene * menup = &menu;

	GameObject* player = new GameObject(new GraphicsComponent("47444.png", { 6, 21,  32, 16 }, { SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 32 * 4, 16 * 4 }), 
										new PlayerInputComponent());
	menu.add(player);
	GameObject* player2 = new GameObject(new GraphicsComponent("47444.png", { 6, 21, 32, 16 }, { 100 , 100, 32 * 4, 16 * 4 }),
										new Player2InputComponent());
	menu.add(player2);
	//Load sounds 
	Audio* audio = Locator::getAudio();
	audio->addSound("slimeball.wav");
	audio->addSound("iceball.wav");

	menu.run();
	return 0;
}