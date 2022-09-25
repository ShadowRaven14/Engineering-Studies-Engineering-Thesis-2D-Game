#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <vector>
#include <conio.h>			// Funkcje getch()
#include <windows.h>		// Funkcje Windows
#include <ctime>			// Funkcje czasowe									 
#include <fstream>			// Funkcje z plikami zewnêtrznymi
//#include "stdafx.h"			// "Powinno" usprawniaæ stabilizacjê i dzia³anie programu
using namespace std;

class Game
{

public:
	Game();
	~Game();

	void init(const char* title, int width, int height, bool fullscreen);

	void handleEvents();
	void update();
	bool running() { return isRunning; }
	void render();
	void clean();

	static SDL_Renderer* renderer;
	static SDL_Event event;

private:
	bool isRunning = false;
	int cnt = 0;
	SDL_Window* window;

};