//#include "Loader.h"
//#include <SDL.h>
//#include <stdio.h>
//#include <string>
//#include <SDL_image.h>
//
////SDL_Surface* loadMedia(const char* file, SDL_Surface* surface,  SDL_Event e)
////{
////	//Loading success flag
////	bool success = true;
////
////	//Load splash image
////	surface = IMG_Load(file);
////	if (surface == NULL) {
////		printf("Unable to load image %s! SDL Error: %s\n", IMG_GetError());
////		success = false;
////	}
////	return surface;
////}
//
////SDL_Surface* loadSurface(std::string path, SDL_Surface* loadedSurface)
////{
////	//Load image at specified path
////	loadedSurface = SDL_LoadBMP(path.c_str());
////	if (loadedSurface == NULL)
////	{
////		printf("Shit!");
////	}
////	return loadedSurface;
////}
//
////bool loadMedia(const char* file)
////{
////	//Loading success flag
////	bool success = true;
////
////	//Load splash image
////	gHelloWorld = SDL_LoadBMP(file);
////	if (gHelloWorld == NULL)
////	{
////		printf("Unable to load image %s! SDL Error: %s\n", SDL_GetError());
////		success = false;
////	}
////	return success;
////}
//
////SDL_Surface* loadSurface(std::string path, SDL_Surface* loadedSurface)
////{
////	//The final optimized image
////	SDL_Surface* optimizedSurface = NULL;
////
////	//Load image at specified path
////	loadedSurface = IMG_Load (path.c_str());
////		if (loadedSurface == NULL)
////		{
////			printf("Shit!");
////		}
////		else
////		{
////			//Convert surface to screen format
////			optimizedSurface = SDL_ConvertSurface(loadedSurface, gScreenSurface->format, NULL);
////			if (optimizedSurface == NULL)
////			{
////				printf("Shit");
////			}
////
////			//Get rid of old loadedSurface
////			SDL_FreeSurface(loadedSurface);
////		}
////		return optimizedSurface;
////}
//
//SDL_Texture* loadTexture(std::string path)
//{
//	//The final texture
//	SDL_Texture* newTexture = NULL;
//
//	//Load image at specified path
//	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
//	if (loadedSurface == NULL)
//	{
//		printf("Unable to load image %s! SDL_image Error %s\n", path.c_str(), IMG_GetError());
//	}
//	else
//	{
//		//Create texture from surface pixels
//		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
//		if (newTexture == NULL)
//		{
//			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
//		}
//
//		//Get rid of old loaded surface
//		SDL_FreeSurface(loadedSurface);
//	}
//	return newTexture;
//}
//
////bool loadMedia()
////{
////	//Loading success flag
////	bool success = true;
////
////	//Load PNG Texture
////	gTexture = loadTexture("foo.jpg");
////	if (gTexture == NULL) {
////		printf("Unable to load image %s! SDL Error: %s\n", SDL_GetError());
////		success = false;
////	}
////	return success;
////}
