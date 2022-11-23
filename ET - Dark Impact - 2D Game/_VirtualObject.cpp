#include "_VirtualObject.h"

//Aktualizowanie obiektu
void _VirtualObject::UpdateInit()
{
	srcRect.h = 64; //Wysokoœæ w pikselach
	srcRect.w = 64; //Szerokoœæ w pikselach
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.h = srcRect.h / 2; //Wysokoœæ w grze
	destRect.w = srcRect.w / 2; //Szerokoœæ w grze
	destRect.x = point.xpos;
	destRect.y = point.ypos;
}

//Renderowanie obiektu
void _VirtualObject::RenderInit()
{
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}
