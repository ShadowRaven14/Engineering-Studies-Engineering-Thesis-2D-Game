#pragma once
#include "_InteractiveObject.h"

class TeleportObject :
    public virtual _InteractiveObject
{
public:
	//Podstawowe
	TeleportObject(unsigned short type); //Konstruktor
	TeleportObject(const char* texturesheet, int x, int y, int des); //Konstruktor
	TeleportObject(const char* texturesheet, Point* point, int des); //Konstruktor
	TeleportObject(const TeleportObject& tempObject); //Konstruktor
	~TeleportObject(); //Destruktor

	//Zaawansowane
	Point coordinatesOfTeleport;
	int destination;
};