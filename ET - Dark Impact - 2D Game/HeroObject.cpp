#include "HeroObject.h"

//PODSTAWOWE
//Konstruktor bohatera
HeroObject::HeroObject(const char* texturesheet, int x, int y)
{
	InitializeHeroMap();
	objTexture = TextureManager::LoadTexture(texturesheet);
	point.xpos = x; point.ypos = y;
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
	point = KeyboardManager::HandleKeyboard(point);

	// OBS£UGA PORUSZANIA
	// WHILE MOVING DOWN
	if (point.input == 's')
	{
		if (point.input == 'a')		// IdŸ w lewo
			point.previnput = 'a';
		else if (point.input == 'd')	// IdŸ w prawo
			point.previnput = 'd';

		//ypos++;
	}
	// WHILE MOVING UP
	else if (point.input == 'w')
	{
		if (point.input == 'a')		// IdŸ w lewo
			point.previnput = 'a';
		else if (point.input == 'd')	// IdŸ w prawo
			point.previnput = 'd';

		//ypos--;
	}
	// WHILE MOVING RIGHT
	else if (point.input == 'd')
	{
		if (point.input == 'w')		// IdŸ w górê
			point.previnput = 'w';
		else if (point.input == 's')	// IdŸ w dó³
			point.previnput = 's';

		//xpos++;
	}
	// WHILE MOVING LEFT
	else if (point.input == 'a')
	{
		if (point.input == 'w')		// IdŸ w góre
			point.previnput = 'w';
		else if (point.input == 's')	// IdŸ w dó³
			point.previnput = 's';

		//xpos--;
	}
}
