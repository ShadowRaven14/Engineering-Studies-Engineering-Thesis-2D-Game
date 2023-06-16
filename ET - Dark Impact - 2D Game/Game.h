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
	//Podstawowe
	Game();
	~Game();
	void Init(const char* title, int width, int height, bool fullscreen);
	void Update(); //Aktualizacja
	void Render(); //Renderowanie
	void Clean();
	void HandleEvents();

	//Zaawansowane
	static SDL_Renderer* mainGameRender;
	static SDL_Event mainGameEvent;
	static bool isGameRunning;
	static bool TestMode;
	static int objectsSize;
	static int windowX, windowY;
	static int gameX, gameY;

private:
	//Zaawansowane
	SDL_Window* mainGameWindow;
};