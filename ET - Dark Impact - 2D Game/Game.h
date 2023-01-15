#pragma once

#include <iostream>
#include "SDL.h"			//G³ówna biblioteka SDL
#include "SDL_image.h"		//SDL zajmuj¹ca siê obrazami
#include "SDL_ttf.h"		//SDL zajmuj¹ca siê tekstami
#include <cstdlib>
#include <ctime>			// Funkcje czasowe									 
#include <fstream>			// Funkcje z plikami zewnêtrznymi
#include <conio.h>			// Funkcje getch()
#include <dos.h>			// Funkcje delay()
#include <windows.h>		// Funkcje Windows
#include <vector>


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

	//static TTF_Font* mainGameFont;
	//static SDL_Surface* mainGameFontSurface;
	//static SDL_Texture* mainGameFontTexture;
	//static SDL_Rect dstrect;

private:
	bool isGameRunning = false;
	SDL_Window* mainGameWindow;
};