#include "Game.h"
#include "TextureManager.h"
#include "SnakeObject.h"
#include "HeroObject.h"
#include "EnemyObject.h"
#include "ChestObject.h"
#include "AppleObject.h"
#include "BackgroundMap.h"
#include "BasicGameLevel.h"

//SnakeObject* snake;
BasicGameLevel* basicLevel;
//HeroObject *hero;
//EnemyObject *enemy1;
//ChestObject *chest1, *chest2, *chest3;
//BackgroundMap* map, *map2;
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

	//snake = new SnakeObject("Assets/head_down.png", 640, 448);
	basicLevel = new BasicGameLevel(
		"Maps/StartingMap.txt", 
		"Assets/crow1.png", 
		"Assets/apple_golden1.png", 
		"Assets/chest1.png");
	//hero = new HeroObject("Assets/crow1.png", 640, 448);
	//map = new BackgroundMap("Maps/StartingMap.txt");
	//enemy1 = new EnemyObject("Assets/apple_golden1.png", 40, 48);
	//chest1 = new ChestObject("Assets/chest1.png");
	//chest2 = new ChestObject("Assets/chest1.png");
	//chest3 = new ChestObject("Assets/chest1.png");
	
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
	basicLevel->basicHero->Update();
	basicLevel->basicEnemy->Update();
	basicLevel->basicChest->Update();
}

//Renderowanie
void Game::render()
{
	SDL_RenderClear(renderer);
	basicLevel->basicMap->DrawMap();
	//snake->Render();
	basicLevel->basicHero->Render();
	basicLevel->basicEnemy->Render();
	basicLevel->basicChest->Render();
	SDL_RenderPresent(renderer);
}

//Czyszczenie
void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}