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

	GameObject* player = new GameObject(new GraphicsComponent("Gradius.png", { 7, 100, 26, 15 }, { SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 26 * 4, 15 * 4 }), 
										new PlayerInputComponent());
	menu.add(player);
	GameObject* player2 = new GameObject(new GraphicsComponent("Gradius.png", { 7, 100, 26, 15 }, { 100 , 100, 26 * 4, 15 * 4 }),
										new Player2InputComponent());
	menu.add(player2);
	//Load sounds
	Audio* audio = Locator::getAudio();
	audio->addSound("slimeball.wav");
	audio->addSound("iceball.wav");

	menu.run();
	return 0;
}