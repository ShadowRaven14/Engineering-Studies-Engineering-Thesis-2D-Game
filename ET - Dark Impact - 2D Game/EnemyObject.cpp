#include "EnemyObject.h"

//Konstruktor wroga
EnemyObject::EnemyObject(const char* texturesheet, int x, int y)
{
	objTexture = TextureManager::LoadTexture(texturesheet);
	point.xpos = x; point.ypos = y;
}

//Aktualizacja wroga
void EnemyObject::Update()
{
	UpdateInit(); //Podstawowa funkcja z klasy interfejsu

	point.xpos++;
	point.ypos++;
}

//Renderowanie wroga
void EnemyObject::Render()
{
	RenderInit(); //Podstawowa funkcja z klasy interfejsu
}
