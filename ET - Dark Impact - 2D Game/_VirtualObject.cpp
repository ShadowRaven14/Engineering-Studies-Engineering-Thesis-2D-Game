#include "_VirtualObject.h"

//Tworzenie obiektu
void _VirtualObject::ObjectInit(const char* texturesheet, int x, int y)
{
	objTexture = TextureManager::LoadTexture(texturesheet);
	cordsOfObject.point.x = x; cordsOfObject.point.y = y;
}

//Aktualizowanie obiektu
void _VirtualObject::UpdateInit()
{
	srcRect.h = 64; //Wysokoœæ w pikselach
	srcRect.w = 64; //Szerokoœæ w pikselach
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.h = srcRect.h / 2; //Wysokoœæ w grze
	destRect.w = srcRect.w / 2; //Szerokoœæ w grze
	destRect.x = cordsOfObject.point.x; //Punkt na mapie wzglêdem X
	destRect.y = cordsOfObject.point.y; //Punkt na mapie wzglêdem Y
}

//Renderowanie obiektu
void _VirtualObject::RenderInit()
{
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
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