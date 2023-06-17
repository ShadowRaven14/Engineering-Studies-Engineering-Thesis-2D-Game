/*Klasa reprezentuj�ca map� w tle.*/

#pragma once
#include "Game.h"
#include "Point.h"
#include "_VirtualMap.h"

class BackgroundMap :
	public virtual _VirtualMap
{
public:
	//Podstawowe
	BackgroundMap(); //Konstruktor
	BackgroundMap(std::string mapname); //Konstruktor
	~BackgroundMap(); //Destruktor
	void Update(); //Aktualizacja //przesuwaj map�
	void Render(); //Renderowanie //rysuj map�

	//Zaawansowane
	void InitializeTextures(); //inicjalizuj tekstury
	static Point middleOFmap;
	static Point heroInMap;
	static int mapShiftX, mapShiftY;
	static int mapX, mapY;
	static int mapCurrentX, mapCurrentY;
};