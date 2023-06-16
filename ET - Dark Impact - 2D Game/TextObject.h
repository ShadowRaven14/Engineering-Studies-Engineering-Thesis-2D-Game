#pragma once
#include "ImageTextureManager.h"
#include "FontTextureManager.h"

class TextObject 
{
public:
	//Podstawowe
	TextObject();
	TextObject(int x, int y);
	TextObject(const char* bnInfo, SDL_Color* bnColor);
	TextObject(const char* bnInfo, SDL_Color* bnColor, int x, int y);
	~TextObject();
	void Update(); //Aktualizacja
	void Render(); //Renderowanie

	//Zaawansowane
	int displayTextX; 
	int displayTextY;
	const char* info;
	SDL_Color* color;
	SDL_Texture* fontTexture;
};

