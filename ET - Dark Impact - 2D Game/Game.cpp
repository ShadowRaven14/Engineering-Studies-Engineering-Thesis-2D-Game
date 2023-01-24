#include "Game.h"
#include "ImageTextureManager.h"
#include "TextTextureManager.h"
#include "GameLevelManager.h"

GameLevelManager *gameLevelManager = nullptr;
SDL_Renderer *Game::mainGameRender = nullptr;
SDL_Event Game::mainGameEvent;
//TTF_Font *Game::mainGameFont;
//SDL_Surface* Game::mainGameFontSurface;
//SDL_Texture* Game::mainGameFontTexture;
//SDL_Rect Game::dstrect;
bool Game::isGameRunning = false;

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
			SDL_SetRenderDrawColor(mainGameRender, 255, 255, 255, 255);

		isGameRunning = true;
	}

	//TTF inicjalizacja
	//const char* text = "Hello there!";
	//mainGameFont = TTF_OpenFont("Fonts/pixel.fon", 25);
	//SDL_Color color = { 255, 255, 255 };
	//mainGameFontSurface = TTF_RenderText_Solid(mainGameFont, text, color);
	//mainGameFontTexture = SDL_CreateTextureFromSurface(Game::mainGameRender, mainGameFontSurface);
	//int texW = 20;  int texH = 20;
	//int displayTextX = 0; int displayTextY = 0;
	//SDL_QueryTexture(mainGameFontTexture, NULL, NULL, &texW, &texH);
	//dstrect = { displayTextX, displayTextY, texW, texH };

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
	//SDL_DestroyTexture(mainGameFontTexture);
	//SDL_FreeSurface(mainGameFontSurface);
	//TTF_CloseFont(mainGameFont);
	TTF_Quit();
	SDL_DestroyWindow(mainGameWindow);
	SDL_DestroyRenderer(mainGameRender);
	SDL_Quit();
}