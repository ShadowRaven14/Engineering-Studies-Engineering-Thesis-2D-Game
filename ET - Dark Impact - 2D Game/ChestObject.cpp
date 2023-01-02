#include "ChestObject.h"

//Konstruktor wroga
ChestObject::ChestObject(const char* texturesheet, int x, int y)
{
	ObjectInit(texturesheet, x, y);  //Podstawowa funkcja z klasy interfejsu
}

//Konstruktor wroga
ChestObject::ChestObject(const char* texturesheet)
{
	RandomizeCoordinates(texturesheet);  //Podstawowa funkcja z klasy interfejsu
}

//Aktualizacja wroga
void ChestObject::Update()
{
	UpdateInit(); //Podstawowa funkcja z klasy interfejsu
}

//Renderowanie wroga
void ChestObject::Render()
{
	RenderInit(); //Podstawowa funkcja z klasy interfejsu
}