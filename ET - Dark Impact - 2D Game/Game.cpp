#include "Game.h"
#include "TextureManager.h"
#include "SnakeObject.h"
#include "HeroObject.h"
#include "EnemyObject.h"
#include "AppleObject.h"
#include "MapBackground.h"

//SnakeObject* snake;
HeroObject* hero;
EnemyObject* enemy1;
BackgroundMap* map;
SDL_Renderer* Game::renderer = nullptr;
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

	//snake = new SnakeObject("Assets/head_down.png", 640, 448);
	hero = new HeroObject("Assets/apple_golden2.png", 640, 448);
	enemy1 = new EnemyObject("Assets/apple_golden1.png", 40, 48);
	map = new BackgroundMap();
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
	//snake->Update();
	hero->Update();
	enemy1->Update();
}

//Renderowanie
void Game::render()
{
	SDL_RenderClear(renderer);
	map->DrawMap();
	//snake->Render();
	hero->Render();
	enemy1->Render();
	SDL_RenderPresent(renderer);
}

//Czyszczenie
void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}