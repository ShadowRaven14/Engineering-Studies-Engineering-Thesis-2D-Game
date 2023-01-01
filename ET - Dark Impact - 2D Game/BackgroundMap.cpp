#include "BackgroundMap.h"
#include "TextureManager.h"
#include <fstream>
#include <string>

BackgroundMap::BackgroundMap(std::string mapname)
{
	std::cout << "THE MAP HAS BEEN CREATED." << std::endl;
	InitializeTextures();
	//LoadMapFromVariable(lvl1);
	LoadStartingMapFromTxt(mapname);
	//ExportMapToTxt("Maps/Exported.txt");

	srcRect.h = 1200; //Wysokoœæ w pikselach
	srcRect.w = 1200; //Szerokoœæ w pikselach
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.h = srcRect.h / 37.5; //Wysokoœæ w grze
	destRect.w = srcRect.w / 37.5; //Szerokoœæ w grze
	destRect.x = 0;
	destRect.y = 0;
}

BackgroundMap::~BackgroundMap()
{
	std::cout << "THE MAP HAS BEEN DESTROYED." << std::endl;
}


void BackgroundMap::InitializeTextures()
{
	blank = TextureManager::LoadTexture("Textures/blank.png");
	sand = TextureManager::LoadTexture("Textures/pix_sand.png");
	stone = TextureManager::LoadTexture("Textures/pix_stone.png");
	snow = TextureManager::LoadTexture("Textures/pix_snow.png");
	wood = TextureManager::LoadTexture("Textures/pix_wood2.png");
	grass = TextureManager::LoadTexture("Textures/pix_grass.png");
	//dirt = TextureManager::LoadTexture("Textures/pix_brown.png");
	//water = TextureManager::LoadTexture("Textures/pix_blue.png");
	//lava = TextureManager::LoadTexture("Textures/pix_red.png");

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
				TextureManager::Draw(sand, srcRect, destRect);
				break;

			case 1:
				TextureManager::Draw(wood, srcRect, destRect);
				break;

			case 2:
				TextureManager::Draw(grass, srcRect, destRect);
				break;

			case 3:
				TextureManager::Draw(stone, srcRect, destRect);
				break;

			case 4:
				TextureManager::Draw(snow, srcRect, destRect);
				break;

			default:
				break;
			}
		}
	}
}