/*Abstrakcyjna klasa. Interfejs rodziny klas Object.*/

#pragma once
#include "Game.h"
#include "ImageTextureManager.h"
#include "KeyboardManager.h"

class _VirtualObject
{
public:
	//Podstawowe
	void BasicInit(const char* texturesheet, int x, int y); //Tworzenie obiektu
	void BasicUpdate(); //Aktualizowanie obiektu
	void BasicRender(); //Renderowanie obiektu
	void RandomizeCoordinates(const char* texturesheet); //Generowanie losowej pozycji

	//Zaawansowane
	SDL_Rect GetSrcRect();
	void SetSrcRect(SDL_Rect newsrcRect);
	SDL_Rect GetDestRect();
	void SetDestRect(SDL_Rect newdestRect);

	SDL_Texture* objTexture; //Tekstura obiektu
	Point cordsOfObject; //Punkt na mapie

protected:
	SDL_Rect srcRect, destRect; //Wymiary obiektu w pikselach, w grze
};

