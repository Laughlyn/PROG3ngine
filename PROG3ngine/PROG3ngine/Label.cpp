#include "Label.h"
#include "System.h"

Label::Label(const SDL_Rect& r, std::string t):Labeled(r, t)
{
}

Label* Label::getInstance(const SDL_Rect& r, std::string t)
{
	return new Label(r, t);
}

void Label::draw()
{
	SDL_RenderCopy(sys.getRenderer(), getTexture(), NULL, &getRect());
}

Label::~Label()
{
}
