/*Abstrakcyjna klasa. Interfejs rodziny klas Object.*/

#pragma once
#include "Game.h"
#include "TextureManager.h"
#include "KeyboardManager.h"

class _VirtualObject
{
public:
	//_VirtualObject(const _VirtualObject& tempHero);
	void ObjectInit(const char* texturesheet, int x, int y); //Tworzenie obiektu
	void UpdateInit(); //Aktualizowanie obiektu
	void RenderInit(); //Renderowanie obiektu
	SDL_Rect GetDestRect();
	void SetDestRect(SDL_Rect newdestRect);
	SDL_Texture* objTexture; //Tekstura obiektu

protected:
	SDL_Rect srcRect, destRect; //Wymiary obiektu w pikselach, w grze
	CoordinatesOfHero cordsOfObject; //Punkt na mapie
};

