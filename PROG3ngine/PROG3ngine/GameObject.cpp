#include "GameObject.h"
#include "System.h"



GameObject::GameObject(const SDL_Rect& r):rect(r)
{
}

void GameObject::draw()
{
	SDL_RenderFillRect(sys.getRenderer(), &rect);
}

GameObject::~GameObject()
{
}
