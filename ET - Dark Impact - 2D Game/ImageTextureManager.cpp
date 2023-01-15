#include "ImageTextureManager.h"

SDL_Texture* ImageTextureManager::LoadTexture(const char* mainGameFontTexture)
{
	SDL_Surface* tempSurface = IMG_Load(mainGameFontTexture);
	SDL_Texture* yourNewTexture = SDL_CreateTextureFromSurface(Game::mainGameRender, tempSurface);
	SDL_FreeSurface(tempSurface);

	return yourNewTexture;
}

void ImageTextureManager::DrawImageTexture(SDL_Texture* imageTexture, SDL_Rect srcRect, SDL_Rect destRect)
{
	SDL_RenderCopy(Game::mainGameRender, imageTexture, &srcRect, &destRect);
}