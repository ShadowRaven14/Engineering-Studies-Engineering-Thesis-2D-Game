#pragma once
#include "Game.h"

class MapBackground
{
public:
	MapBackground();
	~MapBackground();

	void LoadMap(int arr[29][41]);
	void DrawMap();

private:
	SDL_Rect src, dest;
	SDL_Texture* nest;
	SDL_Texture* dirt;
	SDL_Texture* grass;
	SDL_Texture* water;
	SDL_Texture* lava;

	int map[29][45];
};

