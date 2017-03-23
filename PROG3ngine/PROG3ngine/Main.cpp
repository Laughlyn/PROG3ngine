#include "MenuScene.h"
#include "System.h"
#include <random>
#include <math.h>

int main(int argc, char** argsv)
{
	//new MenuScene();
	srand(SDL_GetTicks());
	const Uint8 *state = SDL_GetKeyboardState(NULL);
	bool quit = false;

	SDL_Texture* spriteTexture;
	spriteTexture = IMG_LoadTexture(sys.getRenderer(), "laserBlue01.png");
	SDL_SetTextureBlendMode(spriteTexture, SDL_BLENDMODE_BLEND);

	float centerY = SCREEN_HEIGHT * .5f;
	float centerX = SCREEN_WIDTH * .5f;
	float radiusX = 300;
	float radiusY = 300;
	float speedX = 0.05f;
	float angleX = 0.f;
	float speedY = 0.05f;
	float angleY = 0.f;
	float angle = 0.f;
	float dy, dx;
	int x, y;

	while (!quit)
	{
		SDL_PumpEvents();

		if (state[SDL_SCANCODE_ESCAPE])
		{
			exit(0);
		}

		SDL_SetRenderDrawColor(sys.getRenderer(), 0, 0, 0, 0);

		SDL_RenderClear(sys.getRenderer());

		SDL_SetRenderDrawColor(sys.getRenderer(), 255, 255, 255, 0);
		
		//const SDL_Rect rect = { centerX + std::cos(angleX) * radiusX, centerY + std::sin(angleY) * radiusY, 100, 100 };

		//const SDL_Rect* rectPtr = &rect;
		//SDL_RenderFillRect(sys.getRenderer(), rectPtr);
			
		angleX += speedX / SCREEN_FPS;
		angleY += speedY / SCREEN_FPS;

		SDL_GetMouseState(&x, &y);

		dx = x - int(centerX + std::cos(angleX) * radiusX);
		dy = y - int(centerY + std::sin(angleY) * radiusY);

		angle = (std::atan2(dy, dx) * 180.f) / PI;

		SDL_RenderCopyEx(sys.getRenderer(), spriteTexture, NULL, &SDL_Rect({ int(centerX + std::cos(angleX) * radiusX), int(centerY + std::sin(angleY) * radiusY), 100, 20 }), angle, NULL, SDL_RendererFlip());
		SDL_RenderPresent(sys.getRenderer());
		
	}
	return 0;
}