#include "Game.h"
#include "TextureManager.h"
#include "GameLevelManager.h"

GameLevelManager *gameLevelManager;
SDL_Renderer *Game::mainGameRender = nullptr;
SDL_Event Game::mainGameEvent;
TTF_Font *Game::mainGameFont;
SDL_Surface* Game::surface;
SDL_Texture* Game::texture;
SDL_Rect Game::dstrect;

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
	/*TTF_Font* yourNewFont = TTF_OpenFont("Fonts/arial.ttf", 25);
	SDL_Color fontColor = { 255, 255, 255 };
	SDL_Surface* fontSurface = TTF_RenderText_Solid(yourNewFont,
		"Welcome to Gigi Labs", fontColor);
	SDL_Texture* fontTexture = SDL_CreateTextureFromSurface(Game::mainGameRender, fontSurface);*/
	const char* text = "Hello there!";
	mainGameFont = TTF_OpenFont("Fonts/pixel.fon", 25);
	SDL_Color color = { 255, 255, 255 };
	surface = TTF_RenderText_Solid(mainGameFont, text, color);
	texture = SDL_CreateTextureFromSurface(Game::mainGameRender, surface);
	int texW = 20;  int texH = 20;
	SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
	dstrect = { 0, 0, texW, texH };

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
	SDL_RenderCopy(Game::mainGameRender, texture, NULL, &dstrect);
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
	//SDL_DestroyTexture(fontTexture);
	//SDL_FreeSurface(fontSurface);
	TTF_CloseFont(mainGameFont);
	TTF_Quit();
	SDL_DestroyWindow(mainGameWindow);
	SDL_DestroyRenderer(mainGameRender);
	SDL_Quit();
}