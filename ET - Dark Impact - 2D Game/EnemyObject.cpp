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
	if (cordsOfObject.x >= Game::windowX - 64) //1248
	{
		sx = false;
		objTexture = ImageTextureManager::LoadTexture("Images/HumanMageBlue.png");

	}
	else if (cordsOfObject.x <= 64)
	{
		sx = true;
		objTexture = ImageTextureManager::LoadTexture("Images/HumanMageBlue_GoRight.png");
	}
		

	switch (sx)
	{
	case true:
		cordsOfObject.x = cordsOfObject.x + 4;
		break;

	case false:
		cordsOfObject.x = cordsOfObject.x - 4;
		break;
	}
	

	if (cordsOfObject.y >= Game::windowY - 64) //864
		sy = false;
		
	else if (cordsOfObject.y <= 64)
		sy = true;
		

	switch (sy)
	{
	case true:
		cordsOfObject.y = cordsOfObject.y + 4;
		break;

	case false:
		cordsOfObject.y = cordsOfObject.y - 4;
		break;
	}
}