#ifndef LABEL_H
#define LABEL_H
#include "Labeled.h"
#include <string>

class Label :
	public Labeled
{
public:
	static Label* getInstance(const SDL_Rect& r, std::string t);
	void draw();
	~Label();
protected:
	Label(const SDL_Rect& r, std::string t);
};
#endif