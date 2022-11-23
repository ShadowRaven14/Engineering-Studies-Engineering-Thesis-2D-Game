#include "HeroObject.h"

//Konstruktor bohatera
HeroObject::HeroObject(const char* texturesheet, int x, int y)
{
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
}

//Poruszanie siÍ bohaterem
void HeroObject::MoveWithHero()
{
	// Obs≥uguj input z klawiatury
	point = KeyboardManager::HandleKeyboard(point);

	// OBS£UGA PORUSZANIA
	// WHILE MOVING DOWN
	if (point.input == 's')
	{
		if (point.input == 'a')		// Idü w lewo
			point.previnput = 'a';
		else if (point.input == 'd')	// Idü w prawo
			point.previnput = 'd';

		//ypos++;
	}
	// WHILE MOVING UP
	else if (point.input == 'w')
	{
		if (point.input == 'a')		// Idü w lewo
			point.previnput = 'a';
		else if (point.input == 'd')	// Idü w prawo
			point.previnput = 'd';

		//ypos--;
	}
	// WHILE MOVING RIGHT
	else if (point.input == 'd')
	{
		if (point.input == 'w')		// Idü w gÛrÍ
			point.previnput = 'w';
		else if (point.input == 's')	// Idü w dÛ≥
			point.previnput = 's';

		//xpos++;
	}
	// WHILE MOVING LEFT
	else if (point.input == 'a')
	{
		if (point.input == 'w')		// Idü w gÛre
			point.previnput = 'w';
		else if (point.input == 's')	// Idü w dÛ≥
			point.previnput = 's';

		//xpos--;
	}
}
