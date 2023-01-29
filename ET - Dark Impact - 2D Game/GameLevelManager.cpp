#include "GameLevelManager.h"

GameLevelManager::GameLevelManager()
{
	std::cout << "THE GAME_MANAGER ACTIVATED." << std::endl;

	mainHero = new HeroObject("Images/ElvenTracker.png", new Point(640, 448));

	basicLevel = new GameLevel(
		"Hi! Welcome to level first!",
		new SDL_Color{ 255, 255, 0 },
		"Maps/StartingMap.txt",
		new Point(640, 448),
		"Images/ElvenTracker.png",
		"Images/PortalBlue.png",
		"Images/HumanMageBlue.png",
		"Images/WoodenChest.png",
		"Images/Coin.png");

	secondLevel = new GameLevel(
		"Hi! Welcome to level second!",
		new SDL_Color{ 255, 0, 255 },
		"Maps/Test.txt",
		new Point(640, 448),
		"Images/ElvenTracker.png",
		"Images/PortalRed.png",
		"Images/HumanMageGreen.png",
		"Images/WoodenChest.png",
		"Images/Coin.png");

	thirdLevel = new GameLevel(
		"Hi! Welcome to level third!",
		new SDL_Color{ 0, 255, 255 },
		"Maps/Exported.txt",
		new Point(640, 448),
		"Images/ElvenTracker.png",
		"Images/PortalViolet.png",
		"Images/HumanMageRed.png",
		"Images/WoodenChest.png",
		"Images/Coin.png");

	currentLevel = new GameLevel(
		"Simple text.",
		new SDL_Color{ 255, 255, 255 },
		"Maps/Exported.txt",
		new Point(100, 100),
		"Images/ElvenTracker.png",
		"Images/apple.png",
		"Images/apple.png",
		"Images/apple.png",
		"Images/apple.png");

	ChangeCurrentLevel(basicLevel);
	currentLevelID = 0;
}

void GameLevelManager::Update()
{
	currentLevel->Update();
	mainHero->Update();
	HeroCollideWithCoin(); //Znikaj¹ na wszystkich mapach
	HeroCollideWithChest();
	HeroCollideWithEnemy(); //Znikaj¹ na wszystkich mapach
	HeroCollideWithTeleport();
}

void GameLevelManager::Render()
{
	currentLevel->Render();
	mainHero->Render();
}


Point GameLevelManager::TranslatePoint(SDL_Rect currentPoint)
{
	Point newcurrentPoint;
	newcurrentPoint.x = currentPoint.x;
	newcurrentPoint.y = currentPoint.y;

	return newcurrentPoint;
}

void GameLevelManager::ChangeCurrentLevel(GameLevel* newLevel)
{
	std::cout << "Change level." << std::endl;
	currentLevel->CopyLevel(newLevel);
	mainHero->MoveHeroToPoint(currentLevel->startingPoint);
}



/*
* ROZPATRZ KOLIZJE
*/

//KOLIZJA Z MONET¥
void GameLevelManager::HeroCollideWithCoin()
{
	for (unsigned int i = 0; i < currentLevel->basicCoins.size(); i++)
	{
		if (abs(mainHero->GetDestRect().x - currentLevel->basicCoins[i]->GetDestRect().x) < 20)
		{
			if (abs(mainHero->GetDestRect().y - currentLevel->basicCoins[i]->GetDestRect().y) < 20)
			{
				std::cout << "Coin has been collected!" << std::endl;
				SDL_Delay(10);

				if (mainHero->HandleCoinCollision() == true)
				{
					currentLevel->basicCoins.erase(currentLevel->basicCoins.begin() + i); i--;
				}
			}
		}
	}
}

//KOLIZJA ZE SKRZYNI¥
void GameLevelManager::HeroCollideWithChest()
{
	for (unsigned int i = 0; i < currentLevel->basicChests.size(); i++)
	{
		if (abs(mainHero->GetDestRect().x - currentLevel->basicChests[i]->GetDestRect().x) < 32)
		{
			if (abs(mainHero->GetDestRect().y - currentLevel->basicChests[i]->GetDestRect().y) < 32)
			{
				//SDL_Texture* isTexture = ImageTextureManager::LoadTexture("Textures/WoodenChest.png");
				//&& basicChests[i]->objTexture == isTexture
				if (mainHero->cordsOfObject.input == 'f')
				{
					//std::cout << "Chest has been collected!" << std::endl;
					SDL_Delay(10);

					if (mainHero->HandleChestCollision() == true)
					{
						currentLevel->basicChests[i]->objTexture = ImageTextureManager::LoadTexture("Textures/WoodenChest_Open.png");
						mainHero->cordsOfObject.input = NULL;
					}
				}
			}
		}
	}
}

//KOLIZJA Z WROGIEM
void GameLevelManager::HeroCollideWithEnemy()
{
	for (unsigned int i = 0; i < currentLevel->basicEnemies.size(); i++)
	{
		if (abs(mainHero->GetDestRect().x - currentLevel->basicEnemies[i]->GetDestRect().x) < 32)
		{
			if (abs(mainHero->GetDestRect().y - currentLevel->basicEnemies[i]->GetDestRect().y) < 32)
			{
				//std::cout << "Collision with Enemy! ENGAGE!" << std::endl;
				SDL_Delay(10);

				if (mainHero->HandleEnemyCollision(5) == true)
				{
					currentLevel->basicEnemies.erase(currentLevel->basicEnemies.begin() + i); i--;
				}
			}
		}
	}
}

//KOLIZJA Z TELEPORTEM
void GameLevelManager::HeroCollideWithTeleport()
{
	for (unsigned int i = 0; i < currentLevel->basicTeleports.size(); i++)
	{
		if (abs(mainHero->GetDestRect().x - currentLevel->basicTeleports[i]->GetDestRect().x) < 32)
		{
			if (abs(mainHero->GetDestRect().y - currentLevel->basicTeleports[i]->GetDestRect().y) < 32)
			{
				if (mainHero->cordsOfObject.input == 'f')
				{
					std::cout << "Collision with Teleport!" << std::endl;
					currentLevelID = currentLevel->basicTeleports[i]->destination;
					SDL_Delay(300);

					switch (currentLevelID)
					{
					case 0:
						ChangeCurrentLevel(basicLevel);
						break;

					case 1:
						ChangeCurrentLevel(secondLevel);
						break;

					case 2:
						ChangeCurrentLevel(thirdLevel);
						break;

					default:
						ChangeCurrentLevel(basicLevel);
						currentLevelID = 0;
						break;
					}
					break;
				}
			}
		}
	}
}