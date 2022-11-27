#include "Game.h"
#include "TextureManager.h"
#include "SnakeObject.h"
#include "HeroObject.h"
#include "EnemyObject.h"
#include "ChestObject.h"
#include "AppleObject.h"
#include "BackgroundMap.h"
#include "BasicGameLevel.h"

BasicGameLevel *basicLevel, *secondLevel;
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

	basicLevel = new BasicGameLevel(
		"Maps/StartingMap.txt", 
		"Assets/crow1.png", 
		"Assets/apple_golden1.png", 
		"Assets/chest1.png");
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
	//basicLevel->basicHero->Update();
	//basicLevel->basicEnemy->Update();
	//basicLevel->basicChest->Update();
	basicLevel->Update();
}

//Renderowanie
void Game::render()
{
	SDL_RenderClear(renderer);
	//basicLevel->basicMap->DrawMap();
	//basicLevel->basicHero->Render();
	//basicLevel->basicEnemy->Render();
	//basicLevel->basicChest->Render();
	basicLevel->Render();
	SDL_RenderPresent(renderer);
}

//Czyszczenie
void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}