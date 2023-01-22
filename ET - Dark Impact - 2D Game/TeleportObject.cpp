#include "TeleportObject.h"

//PODSTAWOWE
//Konstruktor bohatera
TeleportObject::TeleportObject(const char* texturesheet, int x, int y, int des)
{
	BasicInit(texturesheet, x, y); //Podstawowa funkcja z klasy interfejsu
	coordinatesOfTeleport.x = x;
	coordinatesOfTeleport.y = y;
	destination = des;
}

//Konstruktor bohatera
TeleportObject::TeleportObject(const char* texturesheet, Point* point, int des)
{
	BasicInit(texturesheet, point->x, point->y); //Podstawowa funkcja z klasy interfejsu
	coordinatesOfTeleport.x = point->x;
	coordinatesOfTeleport.y = point->y;
	destination = des;
}

TeleportObject::TeleportObject(const TeleportObject& tempObject)
{
	objTexture = tempObject.objTexture;
	cordsOfObject = tempObject.cordsOfObject;
}

//Aktualizacja bohatera
void TeleportObject::Update()
{
	BasicUpdate(); //Podstawowa funkcja z klasy interfejsu
}

//Renderowanie bohatera
void TeleportObject::Render()
{
	BasicRender(); //Podstawowa funkcja z klasy interfejsu
}
//PODSTAWOWE