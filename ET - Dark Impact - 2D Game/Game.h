#pragma once

#include <iostream>
#include "SDL.h"			//G��wna biblioteka SDL
#include "SDL_image.h"		//SDL zajmuj�ca si� obrazami
#include "SDL_ttf.h"		//SDL zajmuj�ca si� tekstami
#include <cstdlib>
#include <ctime>			// Funkcje czasowe									 
#include <fstream>			// Funkcje z plikami zewn�trznymi
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
	void HandleEvents();

	static SDL_Renderer* mainGameRender;
	static SDL_Event mainGameEvent;

	//static TTF_Font* mainGameFont;
	//static SDL_Surface* mainGameFontSurface;
	//static SDL_Texture* mainGameFontTexture;
	//static SDL_Rect dstrect;

	static bool isGameRunning;
	static int windowX, windowY;

private:
	
	SDL_Window* mainGameWindow;
};