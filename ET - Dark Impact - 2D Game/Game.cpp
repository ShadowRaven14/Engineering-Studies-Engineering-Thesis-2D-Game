#include "Game.h"
#include "TextureManager.h"
#include "GameLevelManager.h"

GameLevelManager *gameLevelManager;
SDL_Renderer *Game::mainGameRender = nullptr;
SDL_Event Game::mainGameEvent;
TTF_Font *Game::mainGameFont;


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
		mainGameFont = TTF_OpenFont("Fonts/arial.ttf", 25);
		SDL_Color color = { 255, 255, 255 };
		SDL_Surface* surface = TTF_RenderText_Solid(mainGameFont,
			"Welcome to Gigi Labs", color);
		SDL_Texture* texture = SDL_CreateTextureFromSurface(mainGameRender, surface);


		mainGameWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
		mainGameRender = SDL_CreateRenderer(mainGameWindow, -1, 0);

		if (mainGameRender) 
			SDL_SetRenderDrawColor(mainGameRender, 255, 255, 255, 255);

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
	TTF_CloseFont(mainGameFont);
	TTF_Quit();
	SDL_DestroyWindow(mainGameWindow);
	SDL_DestroyRenderer(mainGameRender);
	SDL_Quit();
}