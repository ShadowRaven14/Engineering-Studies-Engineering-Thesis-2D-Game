#include "ChestObject.h"
#include <cstdlib>
#include <ctime>

//Konstruktor wroga
ChestObject::ChestObject(const char* texturesheet, int x, int y)
{
	ObjectInit(texturesheet, x, y);
}

//Konstruktor wroga
ChestObject::ChestObject(const char* texturesheet)
{
	LocateChest(texturesheet);
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

//Generowanie losowej pozycji skrzynki
void ChestObject::LocateChest(const char* texturesheet)
{
	srand(time(NULL));
	int x = rand() % 1312, y = rand() % 928;
	std::cout << x << " " << y << std::endl;
	ObjectInit(texturesheet, x, y);
}