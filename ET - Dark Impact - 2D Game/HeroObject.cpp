#include "HeroObject.h"

//Konstruktor bohatera
HeroObject::HeroObject(const char* texturesheet, int x, int y)
{
	objTexture = TextureManager::LoadTexture(texturesheet);
	xpos = x; ypos = y;
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
	destRect.x = xpos;
	destRect.y = ypos;

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
	HandleKeyboard();

	// OBS£UGA PORUSZANIA
	// WHILE MOVING DOWN
	if (input == 's')
	{
		if (input == 'a')		// IdŸ w lewo
			previnput = 'a';
		else if (input == 'd')	// IdŸ w prawo
			previnput = 'd';

		ypos++;
	}
	// WHILE MOVING UP
	else if (input == 'w')
	{
		if (input == 'a')		// IdŸ w lewo
			previnput = 'a';
		else if (input == 'd')	// IdŸ w prawo
			previnput = 'd';

		ypos--;
	}
	// WHILE MOVING RIGHT
	else if (input == 'd')
	{
		if (input == 'w')		// IdŸ w górê
			previnput = 'w';
		else if (input == 's')	// IdŸ w dó³
			previnput = 's';

		xpos++;
	}
	// WHILE MOVING LEFT
	else if (input == 'a')
	{
		if (input == 'w')		// IdŸ w góre
			previnput = 'w';
		else if (input == 's')	// IdŸ w dó³
			previnput = 's';

		xpos--;
	}
}

//Obs³uga klawiatury
void HeroObject::HandleKeyboard()
{
	//WCZYTYWANIE KLAWIATURY
	if (Game::event.type == SDL_KEYDOWN)
	{
		// WHILE MOVING DOWN
		if (Game::event.key.keysym.sym == SDLK_s)
		{
			std::cout << " Przycisk S" << std::endl;
			previnput = input; input = 's';
		}
		// WHILE MOVING UP
		else if (Game::event.key.keysym.sym == SDLK_w)
		{
			std::cout << " Przycisk W" << std::endl;
			previnput = input; input = 'w';
		}
		// WHILE MOVING RIGHT
		else if (Game::event.key.keysym.sym == SDLK_d)
		{
			std::cout << " Przycisk D" << std::endl;
			previnput = input; input = 'd';
		}
		// WHILE MOVING LEFT
		else if (Game::event.key.keysym.sym == SDLK_a)
		{
			std::cout << " Przycisk A" << std::endl;
			previnput = input; input = 'a';
		}
	}
}
