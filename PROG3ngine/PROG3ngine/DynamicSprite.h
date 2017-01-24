#ifndef DYNAMICSPRITE_H
#define DYNAMICSPRITE_H
#include "Sprite.h"
#include <vector>

class DynamicSprite :
	public Sprite
{
public:
	static DynamicSprite* getInstance(const SDL_Rect& r, std::string t);
	void draw();
	void tick(float timeStep);
//	void keyUp(const SDL_Event& event);
//	void keyDown(const SDL_Event& event);
	void mouseDown(const SDL_Event& event);
	void mouseUp(const SDL_Event& event);
protected:
	DynamicSprite(const SDL_Rect& r, std::string t);
	float posX, posY, velX, velY, accelX, accelY, dirVectX, dirVectY;
private:
	float radians = 0;
	float rotationSpeed = 100;
//	float speed;
//	float angle;
};

#endif