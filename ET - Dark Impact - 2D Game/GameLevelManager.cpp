#include "GameLevelManager.h"

GameLevelManager::GameLevelManager()
{
	std::cout << "THE GAME_MANAGER ACTIVATED." << std::endl;

	switch (Game::TestMode)
	{
	case true:
		std::cout << "GAME IN TEST MODE." << std::endl;

		//Postaæ g³ównego bohatera, jest wspólna dla wszystkich poziomów
		mainHero = new HeroObject("Images/ElvenTracker_GoLeft.png", new Point(640, 448));

		//Poziom Obecny, Tutaj bêdziemy podstawiaæ aktualny poziom
		currentLevel = new GameLevel();

		//Poziom Startowy, od niego zaczynamy
		startLevel = new GameLevel(
			0,
			"Hi! Welcome to start level!",
			new SDL_Color{ 255, 255, 0 },
			"Maps/StartingMap.txt",
			new Point(640, 448),
			"Images/ElvenTracker_GoLeft.png",
			"Images/PortalBlue.png",
			"Images/HumanMageBlue_GoLeft.png",
			"Images/WoodenChest_GoLeft.png",
			"Images/Coin.png");

		//Poziom Pierwszy 
		firstLevel = new GameLevel(
			1,
			"Hi! Welcome to first level!",
			new SDL_Color{ 255, 0, 255 },
			"Maps/Test.txt",
			new Point(640, 448),
			"Images/ElvenTracker_GoLeft.png",
			"Images/PortalRed.png",
			"Images/HumanMageGreen_GoLeft.png",
			"Images/WoodenChest_GoLeft.png",
			"Images/Coin.png");

		//Poziom Pierwszy
		secondLevel = new GameLevel(
			2,
			"Hi! Welcome to second level!",
			new SDL_Color{ 0, 255, 255 },
			"Maps/Exported.txt",
			new Point(640, 448),
			"Images/ElvenTracker_GoLeft.png",
			"Images/PortalViolet.png",
			"Images/HumanMageRed_GoLeft.png",
			"Images/WoodenChest_GoLeft.png",
			"Images/Coin.png");

		break;

	case false:
		std::cout << "GAME IN NORMAL-PLAY MODE." << std::endl;

		//Postaæ g³ównego bohatera, jest wspólna dla wszystkich poziomów
		mainHero = new HeroObject(1);

		//Poziom Obecny, Tutaj bêdziemy podstawiaæ aktualny poziom
		currentLevel = new GameLevel();

		//Poziom Startowy, od niego zaczynamy
		startLevel = new GameLevel(
			0, "Hi! Welcome to start level!", 
			new SDL_Color{ 255, 255, 0 },
			"Maps/StartingMap.txt", 
			new Point(640, 448));

		//Poziom Pierwszy 
		firstLevel = new GameLevel(
			1, "Hi! Welcome to first level!",
			new SDL_Color{ 255, 0, 255 },
			"Maps/Test.txt",
			new Point(640, 448));

		//Poziom Pierwszy
		secondLevel = new GameLevel(
			2, "Hi! Welcome to second level!",
			new SDL_Color{ 0, 255, 255 },
			"Maps/Exported.txt",
			new Point(640, 448));

		break;
	}
	
	//Ustawiamy Poziom Obecny na Poziom Startowy
	ChangeCurrentLevel(startLevel);
	currentLevelID = currentLevel->levelID;
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
	currentLevel = newLevel;
	mainHero->MoveHeroToPoint(currentLevel->startingPoint);
	std::cout << "Change level. Current Level ID = " << currentLevel->levelID << "." << std::endl;
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
				if (mainHero->cordsOfHero.input == 'f')
				{
					if (currentLevel->basicChests[i]->isOpen == false)
					{
						std::cout << "Chest has been collected!" << std::endl;
						SDL_Delay(10);

						if (mainHero->HandleChestCollision(currentLevel->basicChests[i]->worth) == true)
						{
							currentLevel->basicChests[i]->currentObjectTexture = 
								ImageTextureManager::LoadTexture(currentLevel->basicChests[i]->usableTextures[1]);
							mainHero->cordsOfHero.input = NULL;
						}
						currentLevel->basicChests[i]->isOpen = true;
					}
					mainHero->cordsOfHero.input = ' ';
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
				std::cout << "Collision with Enemy! ENGAGE!" << std::endl;
				SDL_Delay(10);

				//Sprawdzamy czy nasza postaæ jest wystarczaj¹co silna aby pokonaæ wroga
				if (mainHero->HandleEnemyCollision(currentLevel->basicEnemies[i]->power) == true)
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
				if (mainHero->cordsOfHero.input == 'f')
				{
					std::cout << "Collision with Teleport!" << std::endl;
					currentLevelID = currentLevel->basicTeleports[i]->destination;
					SDL_Delay(300);

					switch (currentLevelID)
					{
					case 0:
						ChangeCurrentLevel(startLevel);
						break;

					case 1:
						ChangeCurrentLevel(firstLevel);
						break;

					case 2:
						ChangeCurrentLevel(secondLevel);
						break;

					default:
						ChangeCurrentLevel(startLevel);
						currentLevelID = 0;
						break;
					}

					mainHero->cordsOfHero.input = ' ';
				}
			}
		}
	}
}