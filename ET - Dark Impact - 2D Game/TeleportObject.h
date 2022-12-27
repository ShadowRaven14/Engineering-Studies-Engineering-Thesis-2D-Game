#pragma once
#include "_VirtualObject.h"
class TeleportObject :
    public virtual _VirtualObject
{
public:
	//Podstawowe
	TeleportObject(const char* texturesheet, int x, int y, bool b, int start, int end); //Konstruktor bohatera
	TeleportObject(const char* texturesheet, Point* point, bool b, int start, int end); //Konstruktor bohatera
	TeleportObject(const TeleportObject& tempObject);
	~TeleportObject(); //Destruktor bohatera
	void Update(); //Aktualizacja bohatera
	void Render(); //Renderowanie bohatera

	bool isStartingPoint;
	Point coordinatesOfTeleport;
	int startingDestination;
	int endingDestination;
};

