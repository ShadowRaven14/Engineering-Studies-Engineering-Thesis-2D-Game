/*Klasa reprezentuj�ca map� w tle.*/

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
	void Update(); //przesuwaj map�
	void Render(); //rysuj map�

	//Zaawansowane
	void InitializeTextures(); //inicjalizuj tekstury

	static int shiftX, shiftY;
};