#include "BackgroundMap.h"
#include "ImageTextureManager.h"
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

	destRect.h = Game::objectsSize; //srcRect.h / 37.5; //Wysokoœæ w grze
	destRect.w = Game::objectsSize; //srcRect.w / 37.5; //Szerokoœæ w grze
	destRect.x = 0;
	destRect.y = 0;
}

BackgroundMap::~BackgroundMap()
{
	std::cout << "THE MAP HAS BEEN DESTROYED." << std::endl;
}


void BackgroundMap::InitializeTextures()
{
	blank = ImageTextureManager::LoadTexture("Images/_blank.png");
	sand = ImageTextureManager::LoadTexture("Images/pix_sand.png");
	stone = ImageTextureManager::LoadTexture("Images/pix_stone.png");
	snow = ImageTextureManager::LoadTexture("Images/pix_snow.png");
	wood = ImageTextureManager::LoadTexture("Images/pix_wood2.png");
	grass = ImageTextureManager::LoadTexture("Images/pix_grass.png");
	//dirt = ImageTextureManager::LoadTexture("Textures/pix_brown.png");
	//water = ImageTextureManager::LoadTexture("Textures/pix_blue.png");
	//lava = ImageTextureManager::LoadTexture("Textures/pix_red.png");

}

void BackgroundMap::DrawMap()
{
	int type = 0;
	for (int row = 0; row < 29; row++)
	{
		for (int column = 0; column < 41; column++)
		{
			type = map[row][column];

			destRect.x = column * Game::objectsSize;
			destRect.y = row * Game::objectsSize;

			switch (type)
			{
			case 0:
				ImageTextureManager::DrawImageTexture(sand, srcRect, destRect);
				break;

			case 1:
				ImageTextureManager::DrawImageTexture(wood, srcRect, destRect);
				break;

			case 2:
				ImageTextureManager::DrawImageTexture(grass, srcRect, destRect);
				break;

			case 3:
				ImageTextureManager::DrawImageTexture(stone, srcRect, destRect);
				break;

			case 4:
				ImageTextureManager::DrawImageTexture(snow, srcRect, destRect);
				break;

			default:
				break;
			}
		}
	}
}