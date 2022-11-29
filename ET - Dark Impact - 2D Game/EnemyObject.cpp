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

	if(cordsOfHero.point.x<928) cordsOfHero.point.x++;
	else cordsOfHero.point.x--;
	if(cordsOfHero.point.y<1312) cordsOfHero.point.y++;
	else cordsOfHero.point.y--;
}

//Renderowanie wroga
void EnemyObject::Render()
{
	RenderInit(); //Podstawowa funkcja z klasy interfejsu
}
