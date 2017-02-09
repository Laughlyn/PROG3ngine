
#include <SDL.h>
#include "Locator.h"
#include "Audio.h"
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
		velX = 2000.f;
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
			case SDLK_w:		velY = -700.f;
				break;
			case SDLK_d:		velX = 500.f;
				break;
			case SDLK_a:		velX = -400.f;
				break;
 			case SDLK_s:		velY = 500.f;
				break;
			case SDLK_SPACE:	
								//Locate audio service
								Audio* audio = Locator::getAudio();
								if (right)
								{
									GameObject* laser = new Laser({ getRect().x + 20, getRect().y + 109, 54, 9 }, "laserBlue01.png");
									myScene->add(laser);

									//Play sound
									audio->playSound(0);

									right = false;
								}
								else 
								{
									GameObject* laser = new Laser({ getRect().x + 20, getRect().y - 10, 54, 9 }, "laserBlue01.png");
									myScene->add(laser);

									//Play sound
									audio->playSound(1);

									right = true;
								}
								
								

								GameObject* ship = new PhysicsSprite({ getRect().x - 80/10,  getRect().y + 99 / 2, 75/10, 99/10 }, "playerShip1_blue.png");
								myScene->add(ship);
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

	//Load sounds
	Audio* audio = Locator::getAudio();
	audio->addSound("slimeball.wav");
	audio->addSound("iceball.wav");

	menu.run();
	return 0;
}