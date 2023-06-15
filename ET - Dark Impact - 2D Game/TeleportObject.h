#pragma once
#include "__VirtualObject.h"

class TeleportObject :
    public virtual __VirtualObject
{
public:
	//Podstawowe
	TeleportObject(unsigned short type);
	TeleportObject(const char* texturesheet, int x, int y, int des); //Konstruktor bohatera
	TeleportObject(const char* texturesheet, Point* point, int des); //Konstruktor bohatera
	TeleportObject(const TeleportObject& tempObject);
	~TeleportObject(); //Destruktor bohatera
	void Update(); //Aktualizacja bohatera
	void Render(); //Renderowanie bohatera

	//Zaawansowane
	Point coordinatesOfTeleport;
	int destination;
	short challenge;
};