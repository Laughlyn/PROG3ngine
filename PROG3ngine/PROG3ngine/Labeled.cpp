#include "Labeled.h"
#include <string>
#include "System.h"


Labeled::Labeled(const SDL_Rect& r, std::string t):GameObject(r), text(t)
{
	SDL_Surface* textSurface = TTF_RenderText_Solid(sys.getFont(), text.c_str(), { 0,0,0 });
	textTexture = SDL_CreateTextureFromSurface(sys.getRenderer(), textSurface);
	SDL_FreeSurface(textSurface);
}

std::string Labeled::getText() const
{
	return text;
}

void Labeled::setText(std::string newText)
{
	text = newText;
	SDL_Surface* textSurface = TTF_RenderText_Solid(sys.getFont(), text.c_str(), { 0,0,0 });
	//Destroy old texture
	SDL_DestroyTexture(textTexture);
	textTexture = SDL_CreateTextureFromSurface(sys.getRenderer(), textSurface);
	SDL_FreeSurface(textSurface);
}


Labeled::~Labeled()
{
	SDL_DestroyTexture(textTexture);
}
