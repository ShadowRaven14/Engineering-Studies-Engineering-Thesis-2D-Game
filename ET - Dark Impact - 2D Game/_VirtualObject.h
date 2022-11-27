#pragma once
#include "Game.h"
#include "TextureManager.h"
#include "KeyboardManager.h"

class _VirtualObject
{
public:
	void ObjectInit(const char* texturesheet, int x, int y); //Tworzenie obiektu
	void UpdateInit(); //Aktualizowanie obiektu
	void RenderInit(); //Renderowanie obiektu
	SDL_Rect GetDestRect();
	void SetDestRect(SDL_Rect newdestRect);

protected:
	SDL_Texture* objTexture; //Tekstura obiektu
	SDL_Rect srcRect, destRect; //Wymiary obiektu w pikselach, w grze
	PointInMap point; //Punkt na mapie
};

