#include "HeroLayerMap.h"

void HeroLayerMap::InitializeTextures()
{
	blank = TextureManager::LoadTexture("Assets/blank.png");
	apple = TextureManager::LoadTexture("Assets/apple.png");
	pixelapple = TextureManager::LoadTexture("Assets/apple.png");
	pixelgoldenapple = TextureManager::LoadTexture("Assets/apple_golden1.png");
	pixelraven = TextureManager::LoadTexture("Assets/crow1.png");
	pixelsnake = TextureManager::LoadTexture("Assets/pix_green.png");
}

void HeroLayerMap::DrawMap()
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
				TextureManager::Draw(apple, srcRect, destRect);
				break;

			case 1:
				TextureManager::Draw(pixelsnake, srcRect, destRect);
				break;

			case 2:
				TextureManager::Draw(pixelapple, srcRect, destRect);
				break;

			case 3:
				TextureManager::Draw(pixelgoldenapple, srcRect, destRect);
				break;

			case 4:
				TextureManager::Draw(pixelraven, srcRect, destRect);
				break;



			default:
				TextureManager::Draw(apple, srcRect, destRect);
				break;
			}
		}
	}
}