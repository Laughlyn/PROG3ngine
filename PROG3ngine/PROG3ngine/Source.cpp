//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include <string>
#include <SDL_ttf.h>
#include "Constants.h"
#include <SDL_image.h>
#include "LTexture.h"
#include "LButton.h"
#include <sstream>
#include "LTimer.h"
#include "Dot.h"



//Starts up SDL and creates window
bool init();

//Frees media and shuts down SDL
void close();

int main(int argc, char * args[]);

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

//Globally used font
TTF_Font *gFont = NULL;

//Rendered Texture
LTexture gTextTexture;

//Scene textures
LTexture gFooTexture;
LTexture gBackgroundTexture;

//Scene sprites
SDL_Rect gSpriteClips[4];
LTexture gSpriteSheetTexture;

//Walking animation
const int WALKING_ANIMATION_FRAMES = 4;
SDL_Rect gSpriteClips2[WALKING_ANIMATION_FRAMES];
LTexture gSpriteSheetTexture2;

//Mouse button sprites
SDL_Rect gSpriteClips3[BUTTON_SPRITE_TOTAL];
LTexture gButtonSpriteSheetTexture;

//Buttons objects
LButton gButtons[TOTAL_BUTTONS];

LTexture gTimeTextTexture;
LTexture gStartPromptTexture;
LTexture gPausePromptTexture, gFPSTextTexture;

LTexture gDotTexture;

bool init()
{
	//Initilization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not intialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Create renderer for window
			if (V_SYNC)
			{
				gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			}
			else
			{
				gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			}
			if (gRenderer == NULL)
			{
				printf("Renderer could not be initialized! SDL Error: %s\n", SDL_GetError());
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}

				//Initialize SDL_ttf
				if (TTF_Init() == -1)
				{
					printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
					success = false;
				}
			}
		}
	}
	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Open the font
	gFont = TTF_OpenFont("lazy.ttf", 28);
	if (gFont == NULL)
	{
		printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
		success = false;
	}
	else
	{
		//Render text
		SDL_Color textColor = { 0,0,0 };
		if (!gTextTexture.loadFromRenderedText("The quick brown fox jumps over the lazy dog", textColor))
		{
			printf("Failed to render text texture!\n");
			success = false;
		}
	}

	//Load Foo' texture
	if (!gFooTexture.loadFromFile("foo.png"))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}
	else
	{
		//Set standard alpha blending
		gFooTexture.setBlendMode(SDL_BLENDMODE_BLEND);
	}

	//Load background texture
	if (!gBackgroundTexture.loadFromFile("background.png"))
	{
		printf("Failed to load background texture image!\n");
		success = false;
	}

	//Load dot texture
	if (!gDotTexture.loadFromFile("dot.bmp"))
	{
		printf("Failed to load dot texture!\n");
		success = false;
	}

	//Load sprite sheet texture
	if (!gSpriteSheetTexture.loadFromFile("dots.png"))
	{
		printf("Failed to load sprite sheet texture!\n");
		success = false;
	}
	else
	{
		//Set top left sprite
		gSpriteClips[0].x = 0;
		gSpriteClips[0].y = 0;
		gSpriteClips[0].w = 100;
		gSpriteClips[0].h = 100;

		//Set top right sprite
		gSpriteClips[1].x = 100;
		gSpriteClips[1].y = 0;
		gSpriteClips[1].w = 100;
		gSpriteClips[1].h = 100;

		//Set bottom left sprite
		gSpriteClips[2].x = 0;
		gSpriteClips[2].y = 100;
		gSpriteClips[2].w = 100;
		gSpriteClips[2].h = 100;

		//Set bottom right sprite
		gSpriteClips[3].x = 100;
		gSpriteClips[3].y = 100;
		gSpriteClips[3].w = 100;
		gSpriteClips[3].h = 100;
	}

	//Load sprite sheet texture
	if (!gSpriteSheetTexture2.loadFromFile("foo2.png"))
	{
		printf("Failed to load walking animation texture!\n");
		success = false;
	}
	else
	{
		//Set sprite clips
		gSpriteClips2[0].x = 0;
		gSpriteClips2[0].y = 0;
		gSpriteClips2[0].w = 64;
		gSpriteClips2[0].h = 205;

		gSpriteClips2[1].x = 64;
		gSpriteClips2[1].y = 0;
		gSpriteClips2[1].w = 64;
		gSpriteClips2[1].h = 205;

		gSpriteClips2[2].x = 128;
		gSpriteClips2[2].y = 0;
		gSpriteClips2[2].w = 64;
		gSpriteClips2[2].h = 205;

		gSpriteClips2[3].x = 196;
		gSpriteClips2[3].y = 0;
		gSpriteClips2[3].w = 64;
		gSpriteClips2[3].h = 205;
	}

	//Load sprites
	if (!gButtonSpriteSheetTexture.loadFromFile("dots.png"))
	{
		printf("Failed to load button sprite texture!\n");
		success = false;
	}
	else
	{
		//Set sprites
		for (int i = 0; i < BUTTON_SPRITE_TOTAL; ++i)
		{
			gSpriteClips3[i].x = (i%2) * 100;
			gSpriteClips3[i].y = (i/2) * 100;
			gSpriteClips3[i].w = BUTTON_WIDTH;
			gSpriteClips3[i].h = BUTTON_HEIGHT;
		}

		//Set buttons in corners
		gButtons[0].setPosition(0, 0);
		gButtons[1].setPosition(SCREEN_WIDTH - BUTTON_WIDTH, 0);
		gButtons[2].setPosition(0, SCREEN_HEIGHT - BUTTON_HEIGHT);
		gButtons[3].setPosition(SCREEN_WIDTH - BUTTON_WIDTH, SCREEN_HEIGHT - BUTTON_HEIGHT);
	}
	return success;
}

void close()
{

	//Free loaded images
	gTextTexture.free();
	gFooTexture.free();
	gBackgroundTexture.free();

	//Destroy window
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);

	//Quit SDL subsystems
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

int main(int argc, char* args[])
{
	//Start up SDL and create window
	if (!init()) {
		printf("Failed to initialize!\n");
	}
	else
	{
		//Load media
		if ( !loadMedia() )
		{
			printf("Failed to load media!\n");
		}
		else
		{
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			//The dot that will be moving around on the screen
			Dot dot;

			//Set text color as black
			SDL_Color textColor = { 0, 0, 0, 255 };

			//The frames per second timer
			LTimer fpsTimer, capTimer;

			//In memory text stream
			std::stringstream timeText;

			//Start counting frames per second
			int countedFrames = 0;
			fpsTimer.start();

			//Angle of rotation
			double degrees = 0;

			//Flip type
			SDL_RendererFlip flipType = SDL_FLIP_NONE;

			//Current animation frame
			int frame = 0;

			//Modulation component
			Uint8 a = 255;

			//While application is running
			while (!quit)
			{
				//Start cap timer
				capTimer.start();

				//Calculate and correct fps
				float avgFPS = countedFrames / (fpsTimer.getTicks() / 1000.f);
				if (avgFPS > 2000000)
				{
					avgFPS = 0;
				}

				//Handle events on queue
				while (SDL_PollEvent(&e) != 0)
				{
					//User requests quit
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}

					//Handle key presses
					else if (e.type == SDL_KEYDOWN)
					{
						//Increase alpha on w
						if (e.key.keysym.sym == SDLK_w)
						{
							//Cap if over 255
							if (a + 32 > 255)
							{
								a = 255;
							}
							//Increment otherwise
							else
							{
								a += 32;
							}
						}
						//Decrease alpha on s
						else if (e.key.keysym.sym == SDLK_s)
						{
							//Cap if below 0
							if (a - 32 < 0)
							{
								a = 0;
							}
							//Decrement otherwise
							else
							{
								a -= 32;
							}
						}
						else if (e.type == SDL_KEYDOWN)
						{
							switch (e.key.keysym.sym)
							{
							case SDLK_a:
								degrees -= 60;
								break;

							case SDLK_d:
								degrees += 60;
								break;

							case SDLK_q:
								flipType = SDL_FLIP_HORIZONTAL;
								break;

							case SDLK_w:
								flipType = SDL_FLIP_NONE;
								break;

							case SDLK_e:
								flipType = SDL_FLIP_VERTICAL;
								break;
							}
						}
						////Start/stop
						//if (e.key.keysym.sym == SDLK_n)
						//{
						//	if (timer.isStarted())
						//	{
						//		timer.stop();
						//	}
						//	else
						//	{
						//		timer.start();
						//	}
						//}
						////Pause/unpause
						//else if (e.key.keysym.sym == SDLK_m)
						//{
						//	if (timer.isPaused())
						//	{
						//		timer.unpause();
						//	}
						//	else
						//	{
						//		timer.pause();
						//	}
						//}
					}

					//Handle input for the dot
					dot.handleEvent(e);
				}

				//Move the dot
				dot.move();

				//Handle button events
				for (int i = 0; i < TOTAL_BUTTONS; ++i)
				{
					gButtons[i].handleEvent(&e);
				}

				////Set text to be rendered
				//timeText.str("");
				//timeText << "Seconds since start time " << (timer.getTicks() / 1000.f);

				////Render text
				//if (!gTimeTextTexture.loadFromRenderedText(timeText.str().c_str(), textColor))
				//{
				//	printf("Unable to render time texture!\n");
				//}

				//Set text to be rendered
				timeText.str("");
				timeText << "Average Frames Per Second " << avgFPS;

				//Render text
				if (!gFPSTextTexture.loadFromRenderedText(timeText.str().c_str(), textColor))
				{
					printf("Unable to render FPS texture!\n");
				}

				//Clear screen
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				SDL_RenderClear(gRenderer);

				gBackgroundTexture.render(0, 0);

				//Render front blended
				gFooTexture.setAlpha(a);
				gFooTexture.render(240, 100, NULL, degrees, NULL, flipType);

				//Render top left sprite
				gSpriteSheetTexture.render(0, 0, &gSpriteClips[0]);

				//Render top right sprite
				gSpriteSheetTexture.render(SCREEN_WIDTH - gSpriteClips[1].w, 0, &gSpriteClips[1]);

				//Render bottom left sprite
				gSpriteSheetTexture.render(0, SCREEN_HEIGHT - gSpriteClips[2].h, &gSpriteClips[2]);

				//Render bottom right sprite
				gSpriteSheetTexture.render(SCREEN_WIDTH - gSpriteClips[3].w, SCREEN_HEIGHT - gSpriteClips[3].h, &gSpriteClips[3]);

				//Render current frame
				SDL_Rect* currentClip = &gSpriteClips2[frame / 4];
				gSpriteSheetTexture2.render((SCREEN_WIDTH - currentClip->w) / 2, (SCREEN_HEIGHT - currentClip->h) / 2, currentClip);

				//Render current frame
				gTextTexture.render((SCREEN_WIDTH - gTextTexture.getWidth()) / 2, ((SCREEN_HEIGHT - gTextTexture.getHeight()) / 2)+200);

				//Render buttons
				for (int i = 0; i < TOTAL_BUTTONS; ++i)
				{
					gButtons[i].render();
				}

				////Render textures
				//gStartPromptTexture.render((SCREEN_WIDTH - gStartPromptTexture.getWidth()) / 2, 0);
				//gPausePromptTexture.render((SCREEN_WIDTH - gPausePromptTexture.getWidth()) / 2, gStartPromptTexture.getHeight());
				//gTimeTextTexture.render((SCREEN_WIDTH - gTimeTextTexture.getWidth()) / 2, (SCREEN_HEIGHT - gTimeTextTexture.getHeight()) / 2);

				//Render textures
				gFPSTextTexture.render((SCREEN_WIDTH - gFPSTextTexture.getWidth()) / 2, (SCREEN_HEIGHT - gFPSTextTexture.getHeight()) / 2);

				//Render objects
				dot.render();

				//Update screen
				SDL_RenderPresent(gRenderer);
				++countedFrames;

				//If frame finished early
				int frameTicks = capTimer.getTicks();
				if (frameTicks < SCREEN_TICKS_PER_FRAME)
				{
					//Wait remaining time
					SDL_Delay(SCREEN_TICKS_PER_FRAME - frameTicks);
				}

				//Go to next frame
				++frame;

				//Cycle animation
				if (frame / 4 >= WALKING_ANIMATION_FRAMES)
				{
					frame = 0;
				}
			}

		}
	}

	//Free resources and close SDL
	close();
	return 0;
}