#pragma once
#include "Game.h"
#include "TextureManager.h"
#include "KeyboardManager.h"

class _VirtualObject
{
public:
	void UpdateInit(); //Aktualizowanie obiektu
	void RenderInit(); //Renderowanie obiektu

protected:
	SDL_Texture* objTexture; //Tekstura obiektu
	SDL_Rect srcRect, destRect; //Wymiary obiektu w pikselach, w grze
	PointInMap point; //Punkt na mapie
};

