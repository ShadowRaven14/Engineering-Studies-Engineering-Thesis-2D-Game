/*Klasa reprezentuj¹c¹ obiekt gry typu skrzynia.*/

#pragma once
#include "_VirtualObject.h"

class ChestObject
	: public virtual _VirtualObject
{
public:
	//Podstawowe
	ChestObject(const char* texturesheet, int x, int y); //Konstruktor skrzynki
	ChestObject(const char* texturesheet); //Konstruktor skrzynki
	~ChestObject(); //Destruktor skrzynki
	void Update(); //Aktualizacja skrzynki
	void Render(); //Renderowanie skrzynki

	//Zaawansowane
	void LocateChest(const char* texturesheet); //Generowanie losowej pozycji skrzynki
};

