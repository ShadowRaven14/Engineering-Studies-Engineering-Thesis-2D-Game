#include "TeleportObject.h"

//PODSTAWOWE
//Konstruktor bohatera
TeleportObject::TeleportObject(const char* texturesheet, int x, int y, bool b, int start, int end)
{
	ObjectInit(texturesheet, x, y); //Podstawowa funkcja z klasy interfejsu
	//InitTeleportObject(x, y);

	coordinatesOfTeleport.x = x;
	coordinatesOfTeleport.y = y;
	isStartingPoint = b;
	startingDestination = start;
	endingDestination = end;
}

//Konstruktor bohatera
TeleportObject::TeleportObject(const char* texturesheet, Point* point, bool b, int start, int end)
{
	ObjectInit(texturesheet, point->x, point->y); //Podstawowa funkcja z klasy interfejsu
	//InitTeleportObject(point->x, point->y);

	coordinatesOfTeleport.x = point->x;
	coordinatesOfTeleport.y = point->y;
	isStartingPoint = b;
	startingDestination = start;
	endingDestination = end;
}

TeleportObject::TeleportObject(const TeleportObject& tempObject)
{
	objTexture = tempObject.objTexture;
	cordsOfObject = tempObject.cordsOfObject;
}

//Aktualizacja bohatera
void TeleportObject::Update()
{
	UpdateInit(); //Podstawowa funkcja z klasy interfejsu
}

//Renderowanie bohatera
void TeleportObject::Render()
{
	RenderInit(); //Podstawowa funkcja z klasy interfejsu
}
//PODSTAWOWE