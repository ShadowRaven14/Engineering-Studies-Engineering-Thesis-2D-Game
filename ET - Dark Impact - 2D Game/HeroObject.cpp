#include "HeroObject.h"

HeroObject::HeroObject(const char* texturesheet, int x, int y)
{
	objTexture = TextureManager::LoadTexture(texturesheet);
	xpos = x; ypos = y;
}

void HeroObject::Update()
{
	//xpos++;
	//ypos++;

	srcRect.h = 64;
	srcRect.w = 64;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.h = srcRect.h / 2;
	destRect.w = srcRect.w / 2;
	destRect.x = xpos;
	destRect.y = ypos;

	MoveWithHero();
}

void HeroObject::Render()
{
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}

void HeroObject::MoveWithHero()
{
	// Obs≥uguj input z klawiatury
	HandleKeyboard();

	// OBS£UGA PORUSZANIA
	// WHILE MOVING DOWN
	if (previnput == 's')
	{
		if (input == 'a')		// Idü w lewo
			previnput = 'a';
		else if (input == 'd')	// Idü w prawo
			previnput = 'd';

		ypos++;
	}
	// WHILE MOVING UP
	else if (previnput == 'w')
	{
		if (input == 'a')		// Idü w lewo
			previnput = 'a';
		else if (input == 'd')	// Idü w prawo
			previnput = 'd';

		ypos--;
	}
	// WHILE MOVING RIGHT
	else if (previnput == 'd')
	{
		if (input == 'w')		// Idü w gÛrÍ
			previnput = 'w';
		else if (input == 's')	// Idü w dÛ≥
			previnput = 's';

		xpos++;
	}
	// WHILE MOVING LEFT
	else if (previnput == 'a')
	{
		if (input == 'w')		// Idü w gÛre
			previnput = 'w';
		else if (input == 's')	// Idü w dÛ≥
			previnput = 's';

		xpos--;
	}
}

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
