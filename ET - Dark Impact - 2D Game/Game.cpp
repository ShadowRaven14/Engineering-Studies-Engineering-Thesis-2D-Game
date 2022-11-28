#include "Game.h"
#include "TextureManager.h"
#include "LevelManager.h"

LevelManager *levelManager;
SDL_Renderer *Game::renderer = nullptr;
SDL_Event Game::event;

//Kontruktor
Game::Game()
{
	std::cout << "Gra utworzona" << std::endl;
}

//Destruktor
Game::~Game()
{
	std::cout << "Gra zakoñczona" << std::endl;
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
	levelManager = new LevelManager();
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
	levelManager->Update();
}

//Renderowanie
void Game::render()
{
	SDL_RenderClear(renderer);
	levelManager->Render();
	SDL_RenderPresent(renderer);
}

//Czyszczenie
void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}