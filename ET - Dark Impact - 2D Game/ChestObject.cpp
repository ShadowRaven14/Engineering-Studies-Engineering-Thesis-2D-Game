#include "ChestObject.h"

//Konstruktor wroga
ChestObject::ChestObject(const char* texturesheet, int x, int y)
{
	BasicInit(texturesheet, x, y);  //Podstawowa funkcja z klasy interfejsu
	isOpen = false;
}

//Konstruktor wroga
ChestObject::ChestObject(const char* texturesheet)
{
	RandomizeCoordinates(texturesheet);  //Podstawowa funkcja z klasy interfejsu
	isOpen = false;
}

//Aktualizacja wroga
void ChestObject::Update()
{
	BasicUpdate(); //Podstawowa funkcja z klasy interfejsu
}

//Renderowanie wroga
void ChestObject::Render()
{
	BasicRender(); //Podstawowa funkcja z klasy interfejsu
}