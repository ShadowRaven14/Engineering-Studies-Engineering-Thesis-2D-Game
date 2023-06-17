/*Klasa reprezentuj¹ca mapê w tle.*/

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
	void Update(); //Aktualizacja //przesuwaj mapê
	void Render(); //Renderowanie //rysuj mapê

	//Zaawansowane
	void InitializeTextures(); //inicjalizuj tekstury
	static Point middleOFmap;
	static Point heroInMap;
	static int mapShiftX, mapShiftY;
	static int mapX, mapY;
	static int mapCurrentX, mapCurrentY;
};