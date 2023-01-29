#pragma once
#include "Game.h"

class FontTextureManager
{
public:
	//Podstawowe
	static TTF_Font* LoadFont(const char* fileName, int size);
	static TTF_Font* LoadFont(int size);
	static TTF_Font* LoadFont();
	static SDL_Surface* PrepareSurface(TTF_Font* font, const char* text, SDL_Color color);
	static SDL_Surface* PrepareSurface(TTF_Font* font, const char* text);
	static SDL_Texture* PrepareTexture(SDL_Surface* surface);

	//Zaawansowane
	static SDL_Texture* InitTextDisplay(int size, const char* text, SDL_Color color);
	static void DrawTextTexture(SDL_Texture* textTexture, SDL_Rect srcRect, SDL_Rect destRect);
	static void DrawTextTexture(SDL_Texture* textTexture);
};

