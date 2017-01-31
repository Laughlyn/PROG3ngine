#include <SDL.h>
#include "System.h"
#include "Scene.h"
#include "Label.h"
#include "Button.h"
#include "Sprite.h"
#include "DynamicSprite.h"
#include "GameObject.h"
#include "PhysicsSprite.h"

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
		velX = 1000.f;
	}
};

class PlayerShip : public DynamicSprite {
public:
	PlayerShip(const SDL_Rect& r, std::string t) :DynamicSprite(r, t) {}
	PlayerShip(const SDL_Rect& r, std::string t, Scene* s) :DynamicSprite(r, t), myScene(s) {}
	void PlayerShip::keyDown(const SDL_Event& event) override
	{
		if (event.type == SDL_KEYDOWN && event.key.repeat == 0)
		{
			switch (event.key.keysym.sym)
			{
			case SDLK_w:		velY = -500.f;
				break;
			case SDLK_d:		velX = 500.f;
				break;
			case SDLK_a:		velX = -500.f;
				break;
			case SDLK_s:		velY = 500.f;
				break;
			case SDLK_SPACE:	if (right)
								{
									GameObject* laser = new Laser({ getRect().x + 10, getRect().y + 90, 54, 9 }, "laserBlue01.png");
									myScene->add(laser);
									right = false;
								}
								else 
								{
									GameObject* laser = new Laser({ getRect().x + 10, getRect().y, 54, 9 }, "laserBlue01.png");
									myScene->add(laser);
									right = true;
								}

								GameObject* player = new PhysicsSprite({ getRect().x + 75/2,  getRect().y + 99 / 2, 75/10, 99/10 }, "playerShip1_blue.png");
								myScene->add(player);
				break;
			}
		}
	}
	void PlayerShip::keyUp(const SDL_Event & event) override
	{
		if (event.type == SDL_KEYUP)
		{
			switch (event.key.keysym.sym)
			{
			case SDLK_w:		velY = 0;
				break;
			case SDLK_d:		velX = 0;
				break;
			case SDLK_a:		velX = 0;
				break;
			case SDLK_s:		velY = 0;
				break;
			case SDLK_SPACE:
				break;
			}
		}
	}
private:
	Scene* myScene;
	bool right = true;
};

int main(int argc, char** argsv)
{
	Scene menu;
	Scene * menup = &menu;
	Label * lab = Label::getInstance({ 400, 100, 100, 100 }, "0");
	menu.add(lab);
	GameObject* button = new MyButton({ 100, 100 ,200 ,100 }, "Öka", lab);
	menu.add(button);
	GameObject* button2 = new MyButton({ 600, 100 ,200 ,100 }, "Minska", lab);
	menu.add(button2);
	GameObject* player = new PlayerShip({ 300, 300, 75, 99 }, "playerShip1_blue.png", menup);
	menu.add(player);
	menu.run();
	return 0;
}