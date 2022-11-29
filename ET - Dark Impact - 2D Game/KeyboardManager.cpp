#include "KeyboardManager.h"

//Obs³uga klawiatury
CoordinatesOfHero KeyboardManager::HandleKeyboard(CoordinatesOfHero cordsOfHero)
{
	//WCZYTYWANIE KLAWIATURY
	if (Game::event.type == SDL_KEYDOWN)
	{
		// WHILE MOVING DOWN
		if (Game::event.key.keysym.sym == SDLK_s)
		{
			std::cout << " Przycisk S" << std::endl;
			cordsOfHero.previnput = cordsOfHero.input; cordsOfHero.input = 's';

			cordsOfHero.point.y = cordsOfHero.point.y + 32;
		}
		// WHILE MOVING UP
		else if (Game::event.key.keysym.sym == SDLK_w)
		{
			std::cout << " Przycisk W" << std::endl;
			cordsOfHero.previnput = cordsOfHero.input; cordsOfHero.input = 'w';

			cordsOfHero.point.y = cordsOfHero.point.y - 32;
		}
		// WHILE MOVING RIGHT
		else if (Game::event.key.keysym.sym == SDLK_d)
		{
			std::cout << " Przycisk D" << std::endl;
			cordsOfHero.previnput = cordsOfHero.input; cordsOfHero.input = 'd';

			cordsOfHero.point.x = cordsOfHero.point.x + 32;
		}
		// WHILE MOVING LEFT
		else if (Game::event.key.keysym.sym == SDLK_a)
		{
			std::cout << " Przycisk A" << std::endl;
			cordsOfHero.previnput = cordsOfHero.input; cordsOfHero.input = 'a';

			cordsOfHero.point.x = cordsOfHero.point.x - 32;
		}
		return cordsOfHero;
	}
	else return cordsOfHero;
}