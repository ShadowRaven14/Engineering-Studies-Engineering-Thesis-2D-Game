#include "_VirtualObject.h"

//Tworzenie obiektu
void _VirtualObject::BasicInit(const char* texturesheet, int x, int y)
{
	currentObjectTexture = ImageTextureManager::LoadTexture(texturesheet);
	cordsOfObject.x = 0; cordsOfObject.y = 0;
	MoveObjectBy(x, y);
}

//Aktualizowanie obiektu
void _VirtualObject::BasicUpdate()
{
	srcRect.h = 64; //Wysokoœæ w pikselach
	srcRect.w = 64; //Szerokoœæ w pikselach
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.h = Game::objectsSize; //srcRect.h / 2; //Wysokoœæ w grze
	destRect.w = Game::objectsSize; //srcRect.w / 2; //Szerokoœæ w grze
	destRect.x = cordsOfObject.x; //Punkt na mapie wzglêdem X
	destRect.y = cordsOfObject.y; //Punkt na mapie wzglêdem Y
}

//Renderowanie obiektu
void _VirtualObject::BasicRender()
{
	SDL_RenderCopy(Game::mainGameRender, currentObjectTexture, &srcRect, &destRect);
}

//Generowanie losowej pozycji
void _VirtualObject::RandomizeCoordinates(const char* texturesheet)
{
	int x = rand() % (Game::windowX - 64), y = rand() % (Game::windowY - 64);
	//std::cout << x << " " << y << std::endl;
	BasicInit(texturesheet, x, y);
}

void _VirtualObject::MoveObjectBy(int x, int y)
{
	cordsOfObject.x = cordsOfObject.x + x;
	cordsOfObject.y = cordsOfObject.y + y;
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