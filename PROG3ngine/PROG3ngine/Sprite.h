#ifndef SPRITE_H
#define SPRITE_H
#include "GameObject.h"
#include <string>

class Sprite :
	public GameObject
{
public:
	static Sprite* getInstance(const SDL_Rect& r, std::string t);
	void draw();
	~Sprite();
protected:
	Sprite(const SDL_Rect& r, std::string t);
	SDL_Texture* getTexture() const { return spriteTexture; }
private:
	std::string path;
	SDL_Texture* spriteTexture;
};
#endif