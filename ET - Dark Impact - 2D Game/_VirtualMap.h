/*Abstrakcyjna klasa. Interfejs rodziny klas Map.*/

#pragma once
#include "Game.h"
#include "ImageTextureManager.h"

class _VirtualMap
{
public:
	//Zaawansowane
	void LoadMapFromVariable(int arr[29][41]); //Pobierz mapê
	void LoadStartingMapFromTxt(std::string mapname); //Pobierz z pliku txt
	void ExportMapToTxt(std::string name); //Zapisz mapê w pliku txt
	void RandomizeMap(); //Wygeneruj randomow¹ mapê

protected:
	//Zaawansowane
	int map[29][41]; //Tablica mapy gry
	SDL_Rect srcRect, destRect; //Wymiary obiektu w pikselach, w grze

	//Zmienne tekstur
	SDL_Texture* blank;
	SDL_Texture* sand;
	SDL_Texture* wood1;
	SDL_Texture* wood2;
	SDL_Texture* grass;
	SDL_Texture* stone1;
	SDL_Texture* stone2;
	SDL_Texture* stone3;
	SDL_Texture* snow;
	//SDL_Texture* dirt;
	//SDL_Texture* water;
	//SDL_Texture* lava;
};

