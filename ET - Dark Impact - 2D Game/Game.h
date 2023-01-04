#pragma once

#include <iostream>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include <vector>
#include <cstdlib>
#include <ctime>			// Funkcje czasowe									 
#include <fstream>			// Funkcje z plikami zewnêtrznymi
#include <conio.h>			// Funkcje getch()
#include <dos.h>			// Funkcje delay()
#include <windows.h>		// Funkcje Windows


class Game
{
public:
	Game();
	~Game();
	void Init(const char* title, int width, int height, bool fullscreen);
	void Update();
	void Render();
	void Clean();

	bool Running() { return isGameRunning; }
	void HandleEvents();

	static SDL_Renderer* mainGameRender;
	static SDL_Event mainGameEvent;
	static TTF_Font* mainGameFont;

private:
	bool isGameRunning = false;
	SDL_Window* mainGameWindow;
};