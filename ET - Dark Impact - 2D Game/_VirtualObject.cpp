#include "_VirtualObject.h"

//Tworzenie obiektu
void _VirtualObject::BasicInit(const char* texturesheet, int x, int y)
{
	objTexture = ImageTextureManager::LoadTexture(texturesheet);
	cordsOfObject.point.x = x; cordsOfObject.point.y = y;
}

//Aktualizowanie obiektu
void _VirtualObject::BasicUpdate()
{
	srcRect.h = 64; //Wysoko�� w pikselach
	srcRect.w = 64; //Szeroko�� w pikselach
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.h = srcRect.h / 2; //Wysoko�� w grze
	destRect.w = srcRect.w / 2; //Szeroko�� w grze
	destRect.x = cordsOfObject.point.x; //Punkt na mapie wzgl�dem X
	destRect.y = cordsOfObject.point.y; //Punkt na mapie wzgl�dem Y
}

//Renderowanie obiektu
void _VirtualObject::BasicRender()
{
	SDL_RenderCopy(Game::mainGameRender, objTexture, &srcRect, &destRect);
}

//Generowanie losowej pozycji
void _VirtualObject::RandomizeCoordinates(const char* texturesheet)
{
	int x = rand() % 1312, y = rand() % 928;
	//std::cout << x << " " << y << std::endl;
	BasicInit(texturesheet, x, y);
}

SDL_Rect _VirtualObject::GetSrcRect()
{
	return srcRect;
}

void _VirtualObject::SetSrcRect(SDL_Rect newsrcRect)
{
	srcRect = newsrcRect;
}

SDL_Rect _VirtualObject::GetDestRect()
{
	return destRect;
}

void _VirtualObject::SetDestRect(SDL_Rect newdestRect)
{
	destRect = newdestRect;
}