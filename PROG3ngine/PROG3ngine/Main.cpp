#include <SDL.h>
#include "Locator.h"
#include "Audio.h"
#include "System.h"
#include "Scene.h"
#include "GameObject.h"
#include "GraphicsComponent.h"
#include "ButtonInputComponent.h"

int main(int argc, char** argsv)
{
	Scene menu;
	GameObject* button = new GameObject(new GraphicsComponent("47444.png", { 9, 736, 242, 50 }, { (SCREEN_WIDTH / 2) - 242, (SCREEN_HEIGHT / 2) - 50, 242*2, 50*2 }),
		new ButtonInputComponent());
	menu.add(button);
	menu.run();
	return 0;
}