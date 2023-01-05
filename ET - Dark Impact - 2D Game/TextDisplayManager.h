#pragma once
#include "Game.h"

class TextDisplayManager
{
public:
	static TTF_Font* LoadFont(const char* fileName, int size);
	static void DisplayText(TTF_Font* font, const char* text);
};

