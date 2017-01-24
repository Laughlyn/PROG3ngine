#include <SDL.h>
#include "System.h"
#include "Scene.h"
#include "Label.h"
#include "Button.h"
#include "Sprite.h"
#include "DynamicSprite.h"

int value = 0;

class MyButton : public Button {
public:
	MyButton(const SDL_Rect& r, std::string t, Label* d):Button(r,t), display(d) {}
	void perform(std::string str) override
	{
		if (str == "Öka")
		{
			value++;
		}
		else
		{
			value--;
		}
		display->setText(std::to_string(value));
	}
private:
	Label* display;
};

class Laser : public DynamicSprite
{
public:
	Laser(const SDL_Rect& r, std::string t) :DynamicSprite(r, t)
	{
		velY = -1000;
	}
	
	void Laser::tick(float timeStep)
	{

	}
};

class PlayerShip : public DynamicSprite {
public:
	PlayerShip(const SDL_Rect& r, std::string t) :DynamicSprite(r, t) {}

	void PlayerShip::keyDown(const SDL_Event& event)
	{
		if (event.type == SDL_KEYDOWN && event.key.repeat == 0)
		{
			switch (event.key.keysym.sym)
			{
			case SDLK_UP:		accelY = -1000;
				break;
			case SDLK_RIGHT:	accelX = 1000;
				break;
			case SDLK_LEFT:		accelX = -1000;
				break;
			case SDLK_DOWN:		accelY = 1000;
				break;
			case SDLK_SPACE:	
				break;
			}
		}
	}

	void PlayerShip::keyUp(const SDL_Event & event)
	{
		if (event.type == SDL_KEYUP)
		{
			switch (event.key.keysym.sym)
			{
			case SDLK_UP:		accelY = 0;
				break;
			case SDLK_RIGHT:	accelX = 0;
				break;
			case SDLK_LEFT:		accelX = 0;
				break;
			case SDLK_DOWN:		accelY = 0;
				break;
			case SDLK_SPACE:
				break;
			}
		}
	}
};

int main(int argc, char** argsv)
{
	Scene menu;
	GameObject* player = new PlayerShip({ 300, 300, 99, 75 }, "playerShip1_blue.png");
	menu.add(player);
	Label * lab = Label::getInstance({ 400, 100, 100, 100 }, "0");
	menu.add(lab);
	GameObject* button = new MyButton({ 100, 100 ,200 ,100 }, "Öka", lab);
	menu.add(button);
	GameObject* button2 = new MyButton({ 600, 100 ,200 ,100 }, "Minska", lab);
	menu.add(button2);
	menu.run();
	return 0;
}