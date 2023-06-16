/*Klasa reprezentuj¹c¹ obiekt gry typu skrzynia.*/

#pragma once
#include "_InteractiveObject.h"

class ChestObject
	: public virtual _InteractiveObject
{
public:
	//Podstawowe
	ChestObject(unsigned short type); //Konstruktor
	ChestObject(const char* texturesheet, int x, int y); //Konstruktor
	ChestObject(const char* texturesheet); //Konstruktor
	~ChestObject(); //Destruktor

	//Zaawansowane
	bool isOpen = false;
};

