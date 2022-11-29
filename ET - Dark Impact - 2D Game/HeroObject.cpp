#include "HeroObject.h"

//PODSTAWOWE
//Konstruktor bohatera
HeroObject::HeroObject(const char* texturesheet, int x, int y)
{
	InitializeHeroMap();
	ObjectInit(texturesheet, x, y); //Podstawowa funkcja z klasy interfejsu
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
	cordsOfHero = KeyboardManager::HandleKeyboard(cordsOfHero);

	// OBS£UGA PORUSZANIA
	// WHILE MOVING DOWN
	if (cordsOfHero.input == 's')
	{
		if (cordsOfHero.input == 'a')		// IdŸ w lewo
			cordsOfHero.previnput = 'a';
		else if (cordsOfHero.input == 'd')	// IdŸ w prawo
			cordsOfHero.previnput = 'd';

		//ypos++;
	}
	// WHILE MOVING UP
	else if (cordsOfHero.input == 'w')
	{
		if (cordsOfHero.input == 'a')		// IdŸ w lewo
			cordsOfHero.previnput = 'a';
		else if (cordsOfHero.input == 'd')	// IdŸ w prawo
			cordsOfHero.previnput = 'd';

		//ypos--;
	}
	// WHILE MOVING RIGHT
	else if (cordsOfHero.input == 'd')
	{
		if (cordsOfHero.input == 'w')		// IdŸ w górê
			cordsOfHero.previnput = 'w';
		else if (cordsOfHero.input == 's')	// IdŸ w dó³
			cordsOfHero.previnput = 's';

		//xpos++;
	}
	// WHILE MOVING LEFT
	else if (cordsOfHero.input == 'a')
	{
		if (cordsOfHero.input == 'w')		// IdŸ w góre
			cordsOfHero.previnput = 'w';
		else if (cordsOfHero.input == 's')	// IdŸ w dó³
			cordsOfHero.previnput = 's';

		//xpos--;
	}
}
