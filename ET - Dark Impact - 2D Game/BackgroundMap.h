/*Klasa reprezentuj¹ca mapê w tle.*/

#pragma once
#include "Game.h"
#include "_VirtualMap.h"

class BackgroundMap :
	public virtual _VirtualMap
{
public:
	//Podstawowe
	BackgroundMap(std::string mapname);
	~BackgroundMap();

	//Zaawansowane
	void InitializeTextures(); //inicjalizuj tekstury
	void DrawMap(); //rysuj mapê
};