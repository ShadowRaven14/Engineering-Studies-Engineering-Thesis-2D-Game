#pragma once
#include "FontTextureManager.h"
#include "ImageTextureManager.h"
#include "FontTextureManager.h"
#include "_VirtualObject.h"

class TextObject 
	: public virtual _VirtualObject
{
public:
	TextObject();
	TextObject(int x, int y);
	TextObject(const char* bnInfo, SDL_Color* bnColor);
	TextObject(const char* bnInfo, SDL_Color* bnColor, int x, int y);
	~TextObject();
	void Update(); //Aktualizacja
	void Render(); //Renderowanie

	int displayTextX; 
	int displayTextY;

	const char* info;
	SDL_Color* color;
	SDL_Texture* fontTexture;
};

