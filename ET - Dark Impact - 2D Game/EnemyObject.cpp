#include "EnemyObject.h"

//Konstruktor wroga
EnemyObject::EnemyObject(const char* texturesheet, int x, int y)
{
	objTexture = TextureManager::LoadTexture(texturesheet);
	point.xpos = x; point.ypos = y;
}

//Aktualizacja wroga
void EnemyObject::Update()
{
	point.xpos++;
	point.ypos++;

	srcRect.h = 64;
	srcRect.w = 64;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.h = srcRect.h / 2;
	destRect.w = srcRect.w / 2;
	destRect.x = point.xpos;
	destRect.y = point.ypos;
}

//Renderowanie wroga
void EnemyObject::Render()
{
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}
