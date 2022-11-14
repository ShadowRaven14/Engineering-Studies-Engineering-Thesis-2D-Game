#pragma once
#include "Game.h"
#include "TextureManager.h"

class _VirtualObject
{
public:
	void Update(); //Aktualizowanie obiektu
	void Render(); //Renderowanie obiektu

protected:
	int xpos; //Pozycja wzglêdem wykresu -> x
	int ypos; //Pozycja wzglêdem wykresu -> y
	bool qx;
	bool qy;

	SDL_Texture* objTexture; //Tekstura obiektu
	SDL_Rect srcRect, destRect; //Wymiary obiektu w pikselach, w grze
};

