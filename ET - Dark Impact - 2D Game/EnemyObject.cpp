#include "EnemyObject.h"

//Konstruktor wroga
EnemyObject::EnemyObject(const char* texturesheet, int x, int y)
{
	BasicInit(texturesheet, x, y); //Podstawowa funkcja z klasy interfejsu
	sx = sy = true;
}

EnemyObject::EnemyObject(const char* texturesheet)
{
	RandomizeCoordinates(texturesheet); //Podstawowa funkcja z klasy interfejsu
	sx = sy = true;
}

//Aktualizacja wroga
void EnemyObject::Update()
{
	BasicUpdate(); //Podstawowa funkcja z klasy interfejsu
	MoveWithEnemyV1();
}

//Renderowanie wroga
void EnemyObject::Render()
{
	BasicRender(); //Podstawowa funkcja z klasy interfejsu
}

//Poruszanie siê wroga
void EnemyObject::MoveWithEnemyV1()
{
	if (cordsOfObject.point.x >= 1248)
		sx = false;

	else if (cordsOfObject.point.x <= 64)
		sx = true;
		

	switch (sx)
	{
	case true:
		cordsOfObject.point.x = cordsOfObject.point.x + 4;
		break;

	case false:
		cordsOfObject.point.x = cordsOfObject.point.x - 4;
		break;
	}
	

	if (cordsOfObject.point.y >= 864)
		sy = false;
		
	else if (cordsOfObject.point.y <= 64)
		sy = true;
		

	switch (sy)
	{
	case true:
		cordsOfObject.point.y = cordsOfObject.point.y + 4;
		break;

	case false:
		cordsOfObject.point.y = cordsOfObject.point.y - 4;
		break;
	}
}