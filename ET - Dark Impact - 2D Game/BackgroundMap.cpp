#include "BackgroundMap.h"
#include "TextureManager.h"
#include <fstream>
#include <string>

BackgroundMap::BackgroundMap(std::string mapname)
{
	std::cout << "Mapa utworzona" << std::endl;
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
	std::cout << "Mapa zniszczona" << std::endl;
}


void BackgroundMap::InitializeTextures()
{
	blank = TextureManager::LoadTexture("Assets/blank.png");
	sand = TextureManager::LoadTexture("Assets/pix_sand.png");
	stone = TextureManager::LoadTexture("Assets/pix_stone.png");
	snow = TextureManager::LoadTexture("Assets/pix_snow.png");
	wood = TextureManager::LoadTexture("Assets/pix_wood2.png");
	grass = TextureManager::LoadTexture("Assets/pix_grass.png");
	//dirt = TextureManager::LoadTexture("Assets/pix_brown.png");
	//water = TextureManager::LoadTexture("Assets/pix_blue.png");
	//lava = TextureManager::LoadTexture("Assets/pix_red.png");

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