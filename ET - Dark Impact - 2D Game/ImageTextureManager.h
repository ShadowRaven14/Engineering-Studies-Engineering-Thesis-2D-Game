/*Klasa zarz�dzaj�ca �adowaniem tekstur poszczeg�lnych obiekt�w.*/

#pragma once
#include "Game.h"

class ImageTextureManager
{
public:
	static SDL_Texture* LoadTexture(const char* fileName);
	static void DrawImageTexture(SDL_Texture* imageTexture, SDL_Rect srcRect, SDL_Rect destRect);
};