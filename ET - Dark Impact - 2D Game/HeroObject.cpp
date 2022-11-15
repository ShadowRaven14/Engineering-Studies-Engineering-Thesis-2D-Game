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
	srcRect.h = 64; //Wysokoœæ w pikselach
	srcRect.w = 64; //Szerokoœæ w pikselach
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.h = srcRect.h / 2; //Wysokoœæ w grze
	destRect.w = srcRect.w / 2; //Szerokoœæ w grze
	destRect.x = point.xpos;
	destRect.y = point.ypos;

	MoveWithHero();
}

//Renderowanie bohatera
void HeroObject::Render()
{
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
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
