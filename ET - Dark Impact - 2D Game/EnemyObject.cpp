#include "EnemyObject.h"

EnemyObject::EnemyObject(const char* texturesheet, int x, int y)
{
	objTexture = TextureManager::LoadTexture(texturesheet);
	xpos = x; ypos = y;
}

void EnemyObject::Update()
{
	xpos++;
	ypos++;

	srcRect.h = 64;
	srcRect.w = 64;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.h = srcRect.h / 2;
	destRect.w = srcRect.w / 2;
	destRect.x = xpos;
	destRect.y = ypos;
}

void EnemyObject::Render()
{
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}
