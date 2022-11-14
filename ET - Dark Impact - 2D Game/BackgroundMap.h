#pragma once
#include "Game.h"

class BackgroundMap
{
public:
	//Podstawowe
	BackgroundMap();
	~BackgroundMap();

	//Zaawansowane
	void LoadMap(int arr[29][41]); //pobierz mapê
	void DrawMap(); //rysuj mapê

private:
	int map[29][45]; //mapa

	//Zmienne tekstur
	SDL_Texture* nest;
	SDL_Texture* dirt;
	SDL_Texture* grass;
	SDL_Texture* water;
	SDL_Texture* lava;

	SDL_Rect srcRect, destRect; //Wymiary obiektu w pikselach, w grze

	
};