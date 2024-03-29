/*Klasa zarządzająca ładowaniem tekstur poszczególnych obiektów.*/

#pragma once
#include "Game.h"

class ImageTextureManager
{
public:
	//Zaawansowane
	static SDL_Texture* LoadTexture(const char* fileName);
	static void DrawImageTexture(SDL_Texture* imageTexture, SDL_Rect srcRect, SDL_Rect destRect);
};