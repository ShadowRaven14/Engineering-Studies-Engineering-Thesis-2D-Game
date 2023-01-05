#include "TextDisplayManager.h"

TTF_Font* TextDisplayManager::LoadFont(const char* fileName, int size)
{
	TTF_Font* yourNewFont = TTF_OpenFont(fileName, size);

    return yourNewFont;
}

void TextDisplayManager::DisplayText(TTF_Font* font, const char* text)
{
	SDL_Color fontColor = { 255, 255, 255 };
	SDL_Surface* fontSurface = TTF_RenderText_Solid(font, text, fontColor);
	SDL_Texture* fontTexture = SDL_CreateTextureFromSurface(Game::mainGameRender, fontSurface);
}
