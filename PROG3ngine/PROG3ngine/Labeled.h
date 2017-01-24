#ifndef LABELED_H
#define LABELED_H
#include "GameObject.h"
#include <string>
#include <SDL.h>
#include <SDL_ttf.h>

class Labeled :
	public GameObject
{
public:
	Labeled(const SDL_Rect& r, std::string t);
	std::string getText() const;
	void setText(std::string newText);
	~Labeled();
protected:
	SDL_Texture* getTexture() const { return textTexture; }
private:
	std::string text;
	SDL_Texture* textTexture;
};
#endif