#pragma once
#include "Game.h"

class TextDisplayManager
{
public:
	static SDL_Texture* LoadFont(const char* fileName);
	static void DisplayText(std::string* text);
};

