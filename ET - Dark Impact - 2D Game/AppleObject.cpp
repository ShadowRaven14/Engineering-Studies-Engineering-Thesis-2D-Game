#include "AppleObject.h"

AppleObject::AppleObject(const char* texturesheet, int x, int y)
{
	std::cout << "Nowe Apple na ziemi" << std::endl;
	objTexture = TextureManager::LoadTexture(texturesheet);

	srand((unsigned)time(NULL));
	point.xpos = (rand() % (25 - 2) + 1) * 32;
	point.ypos = (rand() % (20 - 2) + 1) * 32;
	qx = true, qy = true;
}

AppleObject::~AppleObject()
{
	//TO-DO
}

void AppleObject::Update()
{
	srcRect.h = 64;
	srcRect.w = 64;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.h = srcRect.h / 2;
	destRect.w = srcRect.w / 2;
	destRect.x = point.xpos;
	destRect.y = point.ypos;
}

void AppleObject::Render()
{
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}