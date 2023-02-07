#include "GameLevelManager.h"

GameLevelManager::GameLevelManager()
{
	std::cout << "THE GAME_MANAGER ACTIVATED." << std::endl;

	//Postaæ g³ównego bohatera, jest wspólna dla wszystkich poziomów
	mainHero = new HeroObject(1);

	//Poziom Startowy, od niego zaczynamy
	basicGameLevels.push_back(
		new GameLevel(
			0, "Hi! Welcome to start level!",
			new SDL_Color{ 255, 255, 0 },
			"Maps/StartingMap.txt",
			new Point(640, 448))
	);

	//Poziom Pierwszy 
	basicGameLevels.push_back(
		new GameLevel(
			1, "Hi! Welcome to first level!",
			new SDL_Color{ 255, 0, 255 },
			"Maps/Test.txt",
			new Point(640, 448))
	);

	//Poziom Drugi
	basicGameLevels.push_back(
		new GameLevel(
			2, "Hi! Welcome to second level!",
			new SDL_Color{ 0, 255, 255 },
			"Maps/Exported.txt",
			new Point(640, 448))
	);

	//Ustawiamy ID tak aby wskaza³o Poziom na którym jesteœmy
	currentLevelID = 0;
}

void GameLevelManager::Update()
{
	basicGameLevels[currentLevelID]->Update();
	//currentLevel->Update();
	mainHero->Update();
	HeroCollideWithTeleport();
	HeroCollideWithChest();
	HeroCollideWithPotion();
	HeroCollideWithCoin();
	HeroCollideWithEnemy();
}

void GameLevelManager::Render()
{
	basicGameLevels[currentLevelID]->Render();
	mainHero->Render();
}


Point GameLevelManager::TranslatePoint(SDL_Rect currentPoint)
{
	Point newcurrentPoint;
	newcurrentPoint.x = currentPoint.x;
	newcurrentPoint.y = currentPoint.y;

	return newcurrentPoint;
}


/*
* ROZPATRZ KOLIZJE
*/

//KOLIZJA Z TELEPORTEM
void GameLevelManager::HeroCollideWithTeleport()
{
	for (unsigned int i = 0; i < basicGameLevels[currentLevelID]->basicTeleports.size(); i++)
	{
		if (abs(mainHero->GetDestRect().x - basicGameLevels[currentLevelID]->basicTeleports[i]->GetDestRect().x) < 32)
		{
			if (abs(mainHero->GetDestRect().y - basicGameLevels[currentLevelID]->basicTeleports[i]->GetDestRect().y) < 32)
			{
				//Sprawadzamy, czy zosta³ nacisniêty przycisk 'f'
				if (mainHero->cordsOfHero.input == 'f')
				{
					std::cout << "Collision with Teleport!" << std::endl;
					SDL_Delay(500);

					//Przenosimy siê na inny Poziom
					currentLevelID = basicGameLevels[currentLevelID]->basicTeleports[i]->destination;
					std::cout << "Change level. Current Level ID = " << currentLevelID << "." << std::endl;
					mainHero->MoveHeroToPoint(basicGameLevels[currentLevelID]->startingPoint);

					mainHero->cordsOfHero.input = ' ';	
				}
			}
		}
	}
}

//KOLIZJA ZE SKRZYNI¥
void GameLevelManager::HeroCollideWithChest()
{
	for (unsigned int i = 0; i < basicGameLevels[currentLevelID]->basicChests.size(); i++)
	{
		if (abs(mainHero->GetDestRect().x - basicGameLevels[currentLevelID]->basicChests[i]->GetDestRect().x) < 32)
		{
			if (abs(mainHero->GetDestRect().y - basicGameLevels[currentLevelID]->basicChests[i]->GetDestRect().y) < 32)
			{
				//Sprawadzamy, czy zosta³ nacisniêty przycisk 'f'
				if (mainHero->cordsOfHero.input == 'f')
				{
					//Upewniamy siê, ¿e skrzynia nie zosta³a ju¿ otwarta
					if (basicGameLevels[currentLevelID]->basicChests[i]->isOpen == false)
					{
						std::cout << "Chest has been collected!" << std::endl;
						SDL_Delay(10);

						//Sprawdzamy czy bohater mo¿e otworzyæ skrzyniê
						if (mainHero->HandleChestCollision(basicGameLevels[currentLevelID]->basicChests[i]->worth) == true)
						{
							basicGameLevels[currentLevelID]->basicChests[i]->currentObjectTexture =
								ImageTextureManager::LoadTexture(basicGameLevels[currentLevelID]->basicChests[i]->usableTextures[1]);
							mainHero->cordsOfHero.input = NULL;
						}
						basicGameLevels[currentLevelID]->basicChests[i]->isOpen = true;
					}
					mainHero->cordsOfHero.input = ' ';
				}
			}
		}
	}
}

//KOLIZJA ZE SKRZYNI¥
void GameLevelManager::HeroCollideWithPotion()
{
	for (unsigned int i = 0; i < basicGameLevels[currentLevelID]->basicPotions.size(); i++)
	{
		if (abs(mainHero->GetDestRect().x - basicGameLevels[currentLevelID]->basicPotions[i]->GetDestRect().x) < 32)
		{
			if (abs(mainHero->GetDestRect().y - basicGameLevels[currentLevelID]->basicPotions[i]->GetDestRect().y) < 32)
			{
				std::cout << "Potion has been collected!" << std::endl;
				SDL_Delay(10);

				//Sprawdzamy czy bohater mo¿e zebraæ miksturê
				if (mainHero->HandlePotionCollision(basicGameLevels[currentLevelID]->basicPotions[i]->power) == true)
				{
					basicGameLevels[currentLevelID]->basicPotions.
						erase(basicGameLevels[currentLevelID]->basicPotions.begin() + i); i--;
				}
			}
		}
	}
}


//KOLIZJA Z MONET¥
void GameLevelManager::HeroCollideWithCoin()
{
	for (unsigned int i = 0; i < basicGameLevels[currentLevelID]->basicCoins.size(); i++)
	{
		if (abs(mainHero->GetDestRect().x - basicGameLevels[currentLevelID]->basicCoins[i]->GetDestRect().x) < 20)
		{
			if (abs(mainHero->GetDestRect().y - basicGameLevels[currentLevelID]->basicCoins[i]->GetDestRect().y) < 20)
			{
				std::cout << "Coin has been collected!" << std::endl;
				SDL_Delay(10);

				//Sprawdzamy czy bohater mo¿e zebraæ monetê
				if (mainHero->HandleCoinCollision() == true)
				{
					basicGameLevels[currentLevelID]->basicCoins.
						erase(basicGameLevels[currentLevelID]->basicCoins.begin() + i); i--;
				}
			}
		}
	}
}

//KOLIZJA Z WROGIEM
void GameLevelManager::HeroCollideWithEnemy()
{
	for (unsigned int i = 0; i < basicGameLevels[currentLevelID]->basicEnemies.size(); i++)
	{
		if (abs(mainHero->GetDestRect().x - basicGameLevels[currentLevelID]->basicEnemies[i]->GetDestRect().x) < 32)
		{
			if (abs(mainHero->GetDestRect().y - basicGameLevels[currentLevelID]->basicEnemies[i]->GetDestRect().y) < 32)
			{
				std::cout << "Collision with Enemy! ENGAGE!" << std::endl;
				SDL_Delay(10);

				//Sprawdzamy czy nasza postaæ jest wystarczaj¹co silna aby pokonaæ wroga
				if (mainHero->HandleEnemyCollision(basicGameLevels[currentLevelID]->basicEnemies[i]->power) == true)
				{
					basicGameLevels[currentLevelID]->basicEnemies.
						erase(basicGameLevels[currentLevelID]->basicEnemies.begin() + i); i--;
					
				}
			}
		}
	}
}