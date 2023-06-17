#include "Game.h"
#include "ImageTextureManager.h"
#include "FontTextureManager.h"
#include "GameLevelManager.h"

GameLevelManager *gameLevelManager = nullptr;
SDL_Renderer *Game::mainGameRender = nullptr;
SDL_Event Game::mainGameEvent;
bool Game::isGameRunning = false;
bool Game::TestMode = false;
int Game::objectsSize = 48;
int Game::windowX = 1312;
int Game::windowY = 928;
int Game::gameX = 41 * Game::objectsSize;
int Game::gameY = 29 * Game::objectsSize;

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
void Game::Init(const char* title, int width, int height, bool fullscreen)
{
	int flags = 0;	
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		mainGameWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
		mainGameRender = SDL_CreateRenderer(mainGameWindow, -1, 0);

		if (mainGameRender) 
			SDL_SetRenderDrawColor(mainGameRender, 10, 10, 10, 10);

		isGameRunning = true;
	}

	//Symulator losowania
	srand((unsigned)time(NULL));

	//Inicjalizacja obiektu zarz¹dzaj¹cego poziomami gry
	gameLevelManager = new GameLevelManager();
}

//Obs³uga wydarzeñ
void Game::HandleEvents()
{
	SDL_PollEvent(&mainGameEvent);

	switch (mainGameEvent.type)
	{
	case SDL_QUIT:
		isGameRunning = false;
		break;
	default:
		break;
	}
}

//Aktualizowanie
void Game::Update()
{
	gameLevelManager->Update();
	//SDL_RenderCopy(Game::mainGameRender, mainGameFontTexture, NULL, &dstrect); //SDL_TTF
	SDL_RenderPresent(Game::mainGameRender);
}

//Renderowanie
void Game::Render()
{
	SDL_RenderClear(mainGameRender);
	gameLevelManager->Render();
	SDL_RenderPresent(mainGameRender);
}

//Czyszczenie
void Game::Clean()
{
	gameLevelManager->Clean();
	TTF_Quit();
	SDL_DestroyWindow(mainGameWindow);
	SDL_DestroyRenderer(mainGameRender);
	SDL_Quit();
}