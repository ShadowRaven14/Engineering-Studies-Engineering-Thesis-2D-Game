#include "TextObject.h"

TextObject::TextObject()
{
	info = "How are you doing?";
	color = new SDL_Color{ 10, 10, 10 };
	fontTexture = FontTextureManager::InitTextDisplay(20, info, *color);
	displayTextX = 0; displayTextY = 40;
}

TextObject::TextObject(int x, int y)
{
	info = "How are you doing?";
	color = new SDL_Color{ 10, 10, 10 };
	fontTexture = FontTextureManager::InitTextDisplay(20, info, *color);
	displayTextX = x; displayTextY = y;
}

TextObject::TextObject(const char* bnInfo, SDL_Color* bnColor)
{
	info = bnInfo;
	color = bnColor;
	fontTexture = FontTextureManager::InitTextDisplay(20, info, *color);
	displayTextX = 0; displayTextY = 40;
}

TextObject::TextObject(const char* bnInfo, SDL_Color* bnColor, int x, int y)
{
	info = bnInfo;
	color = bnColor;
	fontTexture = FontTextureManager::InitTextDisplay(20, info, *color);
	displayTextX = x; displayTextY = y;
}

void TextObject::Update()
{

}

void TextObject::Render()
{
	//Generowanie tekstu
	FontTextureManager::DrawTextTexture(fontTexture, displayTextX, displayTextY);
}
