#include "EnemyObject.h"

//Konstruktor wroga
EnemyObject::EnemyObject(const char* texturesheet, int x, int y)
{
	ObjectInit(texturesheet, x, y); //Podstawowa funkcja z klasy interfejsu
}

//Aktualizacja wroga
void EnemyObject::Update()
{
	UpdateInit(); //Podstawowa funkcja z klasy interfejsu

	if(point.xpos<928) point.xpos++;
	else point.xpos--;
	if(point.ypos<1312) point.ypos++;
	else point.ypos--;
}

//Renderowanie wroga
void EnemyObject::Render()
{
	RenderInit(); //Podstawowa funkcja z klasy interfejsu
}
