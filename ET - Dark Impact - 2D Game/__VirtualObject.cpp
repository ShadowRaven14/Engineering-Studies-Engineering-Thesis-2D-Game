#include "__VirtualObject.h"

//Tworzenie obiektu
void __VirtualObject::BasicInit(const char* texturesheet, int x, int y)
{
	currentObjectTexture = ImageTextureManager::LoadTexture(texturesheet);
	cordsOfObject.x = 0; cordsOfObject.y = 0;
	MoveObjectBy(x, y);
}

//Aktualizowanie obiektu
void __VirtualObject::BasicUpdate()
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
void __VirtualObject::BasicRender()
{
	SDL_RenderCopy(Game::mainGameRender, currentObjectTexture, &srcRect, &destRect);
}

void __VirtualObject::BasicDelete()
{
	usableTextures.clear();
	SDL_DestroyTexture(currentObjectTexture);
	delete currentObjectTexture;
}

//Generowanie losowej pozycji
void __VirtualObject::RandomizeCoordinates(const char* texturesheet)
{
	int x = rand() % (Game::gameX - 64) + ((Game::windowX - Game::gameX) / 2);
	int	y = rand() % (Game::gameY - 64) + ((Game::windowY - Game::gameY) / 2);
	//std::cout << x << " " << y << std::endl;
	BasicInit(texturesheet, x, y);
}

void __VirtualObject::MoveObjectBy(int x, int y)
{
	cordsOfObject.x = cordsOfObject.x + x;
	cordsOfObject.y = cordsOfObject.y + y;
}

SDL_Rect __VirtualObject::GetSrcRect()
{
	return srcRect;
}

void __VirtualObject::SetSrcRect(SDL_Rect newsrcRect)
{
	srcRect = newsrcRect;
}

SDL_Rect __VirtualObject::GetDestRect()
{
	return destRect;
}

void __VirtualObject::SetDestRect(SDL_Rect newdestRect)
{
	destRect = newdestRect;
}