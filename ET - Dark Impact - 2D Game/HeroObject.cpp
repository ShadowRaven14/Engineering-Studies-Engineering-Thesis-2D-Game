#include "HeroObject.h"

//PODSTAWOWE
//Konstruktor bohatera
HeroObject::HeroObject(const char* texturesheet, int x, int y)
{
	InitializeHeroMap();
	ObjectInit(texturesheet, x, y); //Podstawowa funkcja z klasy interfejsu
}

//Konstruktor bohatera
HeroObject::HeroObject(const char* texturesheet, Point* point)
{
	InitializeHeroMap();
	ObjectInit(texturesheet, point->x, point->y); //Podstawowa funkcja z klasy interfejsu
}

HeroObject::HeroObject(const HeroObject& tempObject)
{

	objTexture = tempObject.objTexture;
	//srcRect = tempObject.srcRect;
	//destRect = tempObject.destRect;
	cordsOfObject = tempObject.cordsOfObject;
}

//Aktualizacja bohatera
void HeroObject::Update()
{
	UpdateInit(); //Podstawowa funkcja z klasy interfejsu
	MoveWithHero();
}

//Renderowanie bohatera
void HeroObject::Render()
{
	RenderInit(); //Podstawowa funkcja z klasy interfejsu
	DrawMap();
}
//PODSTAWOWE



//Inicjalizacja mapy bohatera
void HeroObject::InitializeHeroMap()
{
	for (int row = 0; row < 29; row++)
	{
		for (int column = 0; column < 41; column++)
		{
			map[row][column] = 0;
		}
	}
}

//Poruszanie siê bohaterem
void HeroObject::MoveWithHero()
{
	// Obs³uguj input z klawiatury
	cordsOfObject = KeyboardManager::HandleKeyboard(cordsOfObject);

	// OBS£UGA PORUSZANIA
	// WHILE MOVING DOWN
	if (cordsOfObject.input == 's')
	{
		if (cordsOfObject.input == 'a')		// IdŸ w lewo
			cordsOfObject.previnput = 'a';
		else if (cordsOfObject.input == 'd')	// IdŸ w prawo
			cordsOfObject.previnput = 'd';

		//ypos++;
	}
	// WHILE MOVING UP
	else if (cordsOfObject.input == 'w')
	{
		if (cordsOfObject.input == 'a')		// IdŸ w lewo
			cordsOfObject.previnput = 'a';
		else if (cordsOfObject.input == 'd')	// IdŸ w prawo
			cordsOfObject.previnput = 'd';

		//ypos--;
	}
	// WHILE MOVING RIGHT
	else if (cordsOfObject.input == 'd')
	{
		if (cordsOfObject.input == 'w')		// IdŸ w górê
			cordsOfObject.previnput = 'w';
		else if (cordsOfObject.input == 's')	// IdŸ w dó³
			cordsOfObject.previnput = 's';

		//xpos++;
	}
	// WHILE MOVING LEFT
	else if (cordsOfObject.input == 'a')
	{
		if (cordsOfObject.input == 'w')		// IdŸ w góre
			cordsOfObject.previnput = 'w';
		else if (cordsOfObject.input == 's')	// IdŸ w dó³
			cordsOfObject.previnput = 's';

		//xpos--;
	}
}

void HeroObject::MoveHeroToPoint(Point* point)
{
	cordsOfObject.point.x = point->x;
	cordsOfObject.point.y = point->y;
}
