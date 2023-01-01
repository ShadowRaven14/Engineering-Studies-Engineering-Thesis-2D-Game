#include "Game.h"
#include "TextureManager.h"
#include "GameLevelManager.h"

GameLevelManager *gameLevelManager;
SDL_Renderer *Game::renderer = nullptr;
SDL_Event Game::event;

//Kontruktor
Game::Game()
{
	std::cout << "THE GAME HAS STARTED." << std::endl;
}

//Destruktor
Game::~Game()
{
	std::cout << "THE GAME HAS ENDED." << std::endl;
}

//Inicjalizacja
void Game::init(const char* title, int width, int height, bool fullscreen)
{
	int flags = 0;

	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		}

		isRunning = true;
	}

	//Inicjalizacja obiektu zarz¹dzaj¹cego poziomami gry
	gameLevelManager = new GameLevelManager();
}

//Obs³uga wydarzeñ
void Game::handleEvents()
{
	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

//Aktualizowanie
void Game::update()
{
	gameLevelManager->Update();
}

//Renderowanie
void Game::render()
{
	SDL_RenderClear(renderer);
	gameLevelManager->Render();
	SDL_RenderPresent(renderer);
}

//Czyszczenie
void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}