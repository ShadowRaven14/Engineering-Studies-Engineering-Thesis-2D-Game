/*Klasa zarz¹dzaj¹ca ³adowaniem tekstur poszczególnych obiektów.*/

#pragma once
#include "Game.h"

class ImageTextureManager
{
public:
	static SDL_Texture* LoadTexture(const char* fileName);
	static void DrawImageTexture(SDL_Texture* imageTexture, SDL_Rect srcRect, SDL_Rect destRect);
};