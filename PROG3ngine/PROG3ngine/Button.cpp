#include "Button.h"
#include <SDL_image.h>
#include "System.h"

Button* Button::getInstance(const SDL_Rect& r, std::string t)
{
	return new Button(r, t);
}

Button::Button(const SDL_Rect& r, std::string t) : Labeled(r, t)
{
	upIcon = IMG_LoadTexture(sys.getRenderer(), "foo.png");
	downIcon = IMG_LoadTexture(sys.getRenderer(), "wd2.png");
}

void Button::mouseDown(const SDL_Event& event)
{
	SDL_Point p = { event.button.x, event.button.y };
		if (SDL_PointInRect(&p, &getRect()))
		{
			isDown = true;
		}
}

void Button::mouseUp(const SDL_Event& event)
{
	SDL_Point p = { event.button.x, event.button.y };
	if (isDown && SDL_PointInRect(&p, &getRect()))
	{ 
		perform(getText());
	}
	isDown = false;
}

void Button::draw()
{
	if (isDown)
	{
		SDL_RenderCopy(sys.getRenderer(), downIcon, NULL, &getRect());
	}
	else
	{
		SDL_RenderCopy(sys.getRenderer(), upIcon, NULL, &getRect());
	}
	SDL_RenderCopy(sys.getRenderer(), getTexture(), NULL, &getRect());
}

Button::~Button()
{
	SDL_DestroyTexture(upIcon);
	SDL_DestroyTexture(downIcon);
}
