#ifndef BUTTON_H
#define BUTTON_H
#include "Labeled.h"
#include <string>

class Button :
	public Labeled
{
public:
	static Button* getInstance(const SDL_Rect& r, std::string t);
	void mouseDown(const SDL_Event& event);
	void mouseUp(const SDL_Event& event);
	void draw();
	virtual void perform(std::string) {}
	~Button();
protected:
	Button(const SDL_Rect& r, std::string t);
private:
	SDL_Texture* upIcon, *downIcon;
	bool isDown = false;
};

#endif