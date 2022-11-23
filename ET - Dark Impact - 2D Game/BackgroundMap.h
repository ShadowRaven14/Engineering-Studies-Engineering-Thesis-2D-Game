#pragma once
#include "Game.h"
#include "_VirtualMap.h"

class BackgroundMap :
	public virtual _VirtualMap
{
public:
	//Podstawowe
	BackgroundMap();
	~BackgroundMap();

	//Zaawansowane
	void InitializeTextures(); //inicjalizuj tekstury
	void DrawMap(); //rysuj mapê
};