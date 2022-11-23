#include "BackgroundMap.h"
#include "TextureManager.h"
#include <fstream>

BackgroundMap::BackgroundMap()
{
	std::cout << "Mapa utworzona" << std::endl;
	InitializeTextures();
	//LoadMapFromVariable(lvl1);
	LoadStartingMapFromTxt();
	//ExportMapToTxt("Maps/Exported.txt");
	srcRect.x = srcRect.y = 0;
	srcRect.h = destRect.h = 32;
	srcRect.w = destRect.w = 32;
	destRect.x = destRect.y = 0;
}

BackgroundMap::~BackgroundMap()
{
	std::cout << "Mapa zniszczona" << std::endl;
}


void BackgroundMap::InitializeTextures()
{
	nest = TextureManager::LoadTexture("Assets/pix_light_yellow.png");
	dirt = TextureManager::LoadTexture("Assets/pix_brown.png");
	grass = TextureManager::LoadTexture("Assets/pix_green.png");
	water = TextureManager::LoadTexture("Assets/pix_blue.png");
	lava = TextureManager::LoadTexture("Assets/pix_red.png");
}

void BackgroundMap::DrawMap()
{
	int type = 0;
	for (int row = 0; row < 29; row++)
	{
		for (int column = 0; column < 41; column++)
		{
			type = map[row][column];

			destRect.x = column * 32;
			destRect.y = row * 32;

			switch (type)
			{
			case 0:
				TextureManager::Draw(nest, srcRect, destRect);
				break;

			case 1:
				TextureManager::Draw(dirt, srcRect, destRect);
				break;

			case 2:
				TextureManager::Draw(grass, srcRect, destRect);
				break;

			case 3:
				TextureManager::Draw(water, srcRect, destRect);
				break;

			case 4:
				TextureManager::Draw(lava, srcRect, destRect);
				break;

			default:
				break;
			}
		}
	}
}