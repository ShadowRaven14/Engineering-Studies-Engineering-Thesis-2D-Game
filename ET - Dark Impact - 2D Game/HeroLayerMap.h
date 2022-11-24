#pragma once
#include "_VirtualMap.h"

class HeroLayerMap :
    public virtual _VirtualMap
{
public:
	//Zaawansowane
	void DrawMap(); //rysuj mapê
	void InitializeTextures(); //inicjalizuj tekstury

protected:
	//Grafika
	SDL_Texture* apple;
	SDL_Texture* pixelsnake;
	SDL_Texture* pixelapple;
	SDL_Texture* pixelgoldenapple;
	SDL_Texture* pixelraven;
};

