#include "TextTextureManager.h"

TTF_Font* TextDisplayManager::LoadFont(const char* fileName, int size)
{
	TTF_Font* font = TTF_OpenFont(fileName, size);
    return font;
}

TTF_Font* TextDisplayManager::LoadFont(int size)
{
	TTF_Font* font = TTF_OpenFont("Fonts/pixel.fon", size);
	return font;
}

TTF_Font* TextDisplayManager::LoadFont()
{
	TTF_Font* font = TTF_OpenFont("Fonts/pixel.fon", 20);
	return font;
}

SDL_Surface* TextDisplayManager::PrepareSurface(TTF_Font* font, const char* text, SDL_Color color)
{
	SDL_Surface* fontSurface = TTF_RenderText_Solid(font, text, color);
	return fontSurface;
}

SDL_Surface* TextDisplayManager::PrepareSurface(TTF_Font* font, const char* text)
{
	SDL_Color fontColor = { 255, 255, 255 };
	SDL_Surface* fontSurface = TTF_RenderText_Solid(font, text, fontColor);
	return fontSurface;
}

SDL_Texture* TextDisplayManager::PrepareTexture(SDL_Surface* fontSurface)
{
	SDL_Texture* fontTexture = SDL_CreateTextureFromSurface(Game::mainGameRender, fontSurface);
	return fontTexture;
}


SDL_Texture* TextDisplayManager::InitTextDisplay(int size, const char* text, SDL_Color color)
{
	TTF_Font* font = TTF_OpenFont("Fonts/pixel.fon", size);
	SDL_Surface* fontSurface = TTF_RenderText_Solid(font, text, color);
	SDL_Texture* fontTexture = SDL_CreateTextureFromSurface(Game::mainGameRender, fontSurface);

	return fontTexture;
}

void TextDisplayManager::DrawTextTexture(SDL_Texture* fontTexture, SDL_Rect srcRect, SDL_Rect destRect)
{
	int texW = 20;  int texH = 20;
	int displayTextX = 0; int displayTextY = 0;
	SDL_QueryTexture(fontTexture, NULL, NULL, &texW, &texH);
	SDL_Rect dstrect = { displayTextX, displayTextY, texW, texH };
	//SDL_RenderCopy(Game::mainGameRender, mainGameFontTexture, NULL, &dstrect); //SDL_TTF
	SDL_RenderCopy(Game::mainGameRender, fontTexture, &srcRect, &destRect);
}
