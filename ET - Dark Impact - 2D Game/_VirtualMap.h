/*Abstrakcyjna klasa. Interfejs rodziny klas Map.*/

#pragma once
#include "Game.h"
#include "ImageTextureManager.h"

class _VirtualMap
{
public:
	//Zaawansowane
	void LoadMapFromVariable(int arr[29][41]); //pobierz mapê
	void LoadStartingMapFromTxt(std::string mapname); //pobierz z pliku txt
	void ExportMapToTxt(std::string name); //zapisz mapê w pliku txt

protected:
	int map[29][41]; //mapa
	SDL_Rect srcRect, destRect; //Wymiary obiektu w pikselach, w grze

	//Zmienne tekstur
	SDL_Texture* blank;
	SDL_Texture* sand;
	//SDL_Texture* dirt;
	SDL_Texture* stone;
	SDL_Texture* snow;
	SDL_Texture* wood;
	SDL_Texture* grass;
	//SDL_Texture* water;
	//SDL_Texture* lava;
};

