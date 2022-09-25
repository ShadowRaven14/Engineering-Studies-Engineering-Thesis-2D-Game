#pragma once
#include "Game.h"

class AppleObject
{

public:
	AppleObject(const char* texturesheet, int x, int y);
	~AppleObject();

	void Update();
	void Render();


private:
	int xpos;
	int ypos;
	bool qx;
	bool qy;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;

};

