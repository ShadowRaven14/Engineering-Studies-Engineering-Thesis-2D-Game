#pragma once
#include "Game.h"

class _VirtualMap
{
public:
	//Zaawansowane
	void LoadMap(int arr[29][41]); //pobierz mapê
	void DrawMap(); //rysuj mapê

private:
	int map[29][45]; //mapa
	SDL_Rect srcRect, destRect; //Wymiary obiektu w pikselach, w grze
};

