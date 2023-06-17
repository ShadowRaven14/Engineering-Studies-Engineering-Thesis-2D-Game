/*Abstrakcyjna klasa. Interfejs rodziny klas Object.*/

#pragma once
#include "Game.h"
#include "ImageTextureManager.h"
#include "Point.h"

class __VirtualObject
{
public:
	//Podstawowe
	void BasicInit(const char* texturesheet, int x, int y); //Tworzenie obiektu
	void BasicUpdate(); //Aktualizowanie obiektu
	void BasicRender(); //Renderowanie obiektu
	void BasicDelete(); //Renderowanie obiektu

	void RandomizeCoordinates(const char* texturesheet); //Generowanie losowej pozycji
	
	void MoveObjectBy(int x, int y);

	//Zaawansowane
	SDL_Rect GetSrcRect();
	void SetSrcRect(SDL_Rect newsrcRect);
	SDL_Rect GetDestRect();
	void SetDestRect(SDL_Rect newdestRect);

	std::vector <const char*> usableTextures;
	SDL_Texture* currentObjectTexture; //Tekstura obiektu
	Point cordsOfObject = Point (0,0); //Punkt na mapie

protected:
	SDL_Rect srcRect = { 0 }, destRect = { 0 }; //Wymiary obiektu w pikselach, w grze
};

