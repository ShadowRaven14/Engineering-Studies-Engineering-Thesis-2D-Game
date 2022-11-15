#include "KeyboardManager.h"

//Obs³uga klawiatury
PointInMap KeyboardManager::HandleKeyboard(PointInMap point)
{
	//WCZYTYWANIE KLAWIATURY
	if (Game::event.type == SDL_KEYDOWN)
	{
		// WHILE MOVING DOWN
		if (Game::event.key.keysym.sym == SDLK_s)
		{
			std::cout << " Przycisk S" << std::endl;
			point.previnput = point.input; point.input = 's';

			point.ypos = point.ypos + 32;
		}
		// WHILE MOVING UP
		else if (Game::event.key.keysym.sym == SDLK_w)
		{
			std::cout << " Przycisk W" << std::endl;
			point.previnput = point.input; point.input = 'w';

			point.ypos = point.ypos - 32;
		}
		// WHILE MOVING RIGHT
		else if (Game::event.key.keysym.sym == SDLK_d)
		{
			std::cout << " Przycisk D" << std::endl;
			point.previnput = point.input; point.input = 'd';

			point.xpos = point.xpos + 32;
		}
		// WHILE MOVING LEFT
		else if (Game::event.key.keysym.sym == SDLK_a)
		{
			std::cout << " Przycisk A" << std::endl;
			point.previnput = point.input; point.input = 'a';

			point.xpos = point.xpos - 32;
		}
		return point;
	}
	else return point;
}