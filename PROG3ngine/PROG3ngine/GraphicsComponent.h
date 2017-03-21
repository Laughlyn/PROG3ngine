#pragma once
#include "GameObject.h"
#include <SDL_image.h>
#include <string>
#include "System.h"
#include <vector>

class GameObject;

class GraphicsComponent
{
public:
	GraphicsComponent(std::string const & path);
	GraphicsComponent(std::string const & path, int scale);
	GraphicsComponent(std::string const & path, SDL_Rect & s);
	GraphicsComponent(std::string const & path, SDL_Rect & s, int scale);
	GraphicsComponent(std::string const & path, std::vector<SDL_Rect>&);
	GraphicsComponent(std::string const & path, std::vector<SDL_Rect>&, int scale);
	GraphicsComponent(std::string const & path, std::vector<SDL_Rect>&, bool loop);
	GraphicsComponent(std::string const & path, std::vector<SDL_Rect>&, int scale, bool loop);

	GraphicsComponent(SDL_Texture* texture);
	GraphicsComponent(SDL_Texture* texture, SDL_Rect s, int scale);
	GraphicsComponent(SDL_Texture* texture, std::vector<SDL_Rect>, int scale);
	
	virtual void update(GameObject & gameObject, float timeStep);
	SDL_Texture* getTexture();
	SDL_Rect & getdRect();
	virtual ~GraphicsComponent();

protected:
	bool sharingTexture = false;
	bool animated = false;
	bool loop = false;
	Uint32 timer = 0;
	int currentFrame = 0;
	int scale = 1;
	std::vector<SDL_Rect> frameClips;
	SDL_Texture* spriteTexture;
	SDL_Rect sRect = { 0, 0, 0, 0 };
	SDL_Rect dRect = { 0, 0, 0, 0 };
};
