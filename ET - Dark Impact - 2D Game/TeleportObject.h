#pragma once
#include "_VirtualObject.h"
class TeleportObject :
    public virtual _VirtualObject
{
public:
	//Podstawowe
	TeleportObject(const char* texturesheet, int x, int y, int des); //Konstruktor bohatera
	TeleportObject(const char* texturesheet, Point* point, int des); //Konstruktor bohatera
	TeleportObject(const TeleportObject& tempObject);
	~TeleportObject(); //Destruktor bohatera
	void Update(); //Aktualizacja bohatera
	void Render(); //Renderowanie bohatera

	Point coordinatesOfTeleport;
	int destination;
};

