/*Klasa reprezentuj¹c¹ obiekt gry typu skrzynia.*/

#pragma once
#include "__VirtualObject.h"

class ChestObject
	: public virtual __VirtualObject
{
public:
	//Podstawowe
	ChestObject(unsigned short type);
	ChestObject(const char* texturesheet, int x, int y); //Konstruktor skrzynki
	ChestObject(const char* texturesheet); //Konstruktor skrzynki
	~ChestObject(); //Destruktor skrzynki
	void Update(); //Aktualizacja skrzynki
	void Render(); //Renderowanie skrzynki

	bool isOpen;
	short worth;
};

