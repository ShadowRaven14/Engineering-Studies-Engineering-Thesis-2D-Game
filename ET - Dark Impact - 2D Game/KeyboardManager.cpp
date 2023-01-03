#include "KeyboardManager.h"

//Obs³uga klawiatury
CoordinatesOfHero KeyboardManager::HandleKeyboard(CoordinatesOfHero cordsOfObject)
{
	//WCZYTYWANIE KLAWIATURY
	if (Game::mainGameEvent.type == SDL_KEYDOWN)
	{
		// WHILE MOVING DOWN
		if (Game::mainGameEvent.key.keysym.sym == SDLK_s)
		{
			//std::cout << " Przycisk S" << std::endl;
			cordsOfObject.previnput = cordsOfObject.input; cordsOfObject.input = 's';
			cordsOfObject.point.y = cordsOfObject.point.y + 16;
		}
		// WHILE MOVING UP
		else if (Game::mainGameEvent.key.keysym.sym == SDLK_w)
		{
			//std::cout << " Przycisk W" << std::endl;
			cordsOfObject.previnput = cordsOfObject.input; cordsOfObject.input = 'w';
			cordsOfObject.point.y = cordsOfObject.point.y - 16;
		}
		// WHILE MOVING RIGHT
		else if (Game::mainGameEvent.key.keysym.sym == SDLK_d)
		{
			//std::cout << " Przycisk D" << std::endl;
			cordsOfObject.previnput = cordsOfObject.input; cordsOfObject.input = 'd';
			cordsOfObject.point.x = cordsOfObject.point.x + 16;
		}
		// WHILE MOVING LEFT
		else if (Game::mainGameEvent.key.keysym.sym == SDLK_a)
		{
			//std::cout << " Przycisk A" << std::endl;
			cordsOfObject.previnput = cordsOfObject.input; cordsOfObject.input = 'a';
			cordsOfObject.point.x = cordsOfObject.point.x - 16;
		}
		// WHILE MOVING LEFT
		else if (Game::mainGameEvent.key.keysym.sym == SDLK_f)
		{
			//std::cout << " Przycisk F" << std::endl;
			cordsOfObject.previnput = cordsOfObject.input; cordsOfObject.input = 'f';
		}
		return cordsOfObject;
	}
	else return cordsOfObject;
}