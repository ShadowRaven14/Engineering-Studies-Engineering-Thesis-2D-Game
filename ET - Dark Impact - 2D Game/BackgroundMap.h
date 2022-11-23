#pragma once
#include "Game.h"
#include "_VirtualMap.h"

class BackgroundMap :
	public _VirtualMap
{
public:
	//Podstawowe
	BackgroundMap();
	~BackgroundMap();

	//Zaawansowane
	void LoadMap(int arr[29][41]); //pobierz mapê
	void LoadMapFromTxt(); //pobierz mapê
	void ExportMapToTxt(); //zapisz mapê w pliku txt
	void DrawMap(); //rysuj mapê

private:

	//Zmienne tekstur
	SDL_Texture* nest;
	SDL_Texture* dirt;
	SDL_Texture* grass;
	SDL_Texture* water;
	SDL_Texture* lava;
};