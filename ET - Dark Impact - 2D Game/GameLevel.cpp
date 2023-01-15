#include "GameLevel.h"

GameLevel::GameLevel(const char* bnInfo, SDL_Color* bnColor, std::string bnMap, Point* bnStart, const char* bnHero, const char* bnTel,
	const char* bnEnemy, const char* bnChest, const char* bnCoin, Point* bnTeleport)
{
	std::cout << "THE GAME_LEVEL LOADED." << std::endl;

	//Wyœwietlenie tekstu powitalnego
	//welcomeInfo = "Hi! Welcome to new game level!";
	//welcomeColor = { 255, 255, 255 };
	//TextTextureManager::InitTextDisplay(25, welcomeInfo, welcomeColor);
	welcomeInfo = bnInfo;
	welcomeColor = bnColor;
	SDL_Delay(500);

	//Przygotowanie mapy i bohatera
	basicMap = new BackgroundMap(bnMap);
	startingPoint = bnStart;
	basicHero = new HeroObject(bnHero, startingPoint);

	//Dodanie elementów do wektora basicEnemies
	TeleportObject* basicTeleport1 = new TeleportObject("Textures/apple.png", 656, 620, 0);
	TeleportObject* basicTeleport2 = new TeleportObject("Textures/apple_golden1.png", 262, 310, 1);
	TeleportObject* basicTeleport3 = new TeleportObject("Textures/apple_golden2.png", 1050, 310, 2);
	basicTeleports.push_back(basicTeleport1);
	basicTeleports.push_back(basicTeleport2);
	basicTeleports.push_back(basicTeleport3);

	//Dodanie elementów do wektora basicEnemies
	for (int i = 0; i < 3; i++)
	{
		EnemyObject* basicEnemy = new EnemyObject(bnEnemy);
		basicEnemies.push_back(basicEnemy);
	}

	//Dodanie elementów do wektora basicChests
	for (int i = 0; i < 5; i++)
	{
		ChestObject* basicChest = new ChestObject(bnChest);
		basicChests.push_back(basicChest);
	}

	//Dodanie elementów do wektora basicCoins
	for (int i = 0; i < 20; i++)
	{
		CoinObject* basicCoin = new CoinObject(bnCoin);
		basicCoins.push_back(basicCoin);
	}

	//ustawienie punktu teleportu
	teleportPoint = bnTeleport;
}

GameLevel::GameLevel(const GameLevel& tempLevel)
{
	welcomeInfo = tempLevel.welcomeInfo; //upewniæ siê czy dobrze
	startingPoint = tempLevel.startingPoint;
	basicMap = tempLevel.basicMap;
	basicHero = tempLevel.basicHero;
	std::cout << "KOPIOWANY Punkt:" << startingPoint->x << startingPoint->y << std::endl;
	basicHero->MoveHeroToPoint(startingPoint);
	for (unsigned int i = 0; i < basicTeleports.size(); i++) basicTeleports[i] = tempLevel.basicTeleports[i];
	for (unsigned int i = 0; i < basicEnemies.size(); i++) basicEnemies[i] = tempLevel.basicEnemies[i];
	for (unsigned int i = 0; i < basicChests.size(); i++) basicChests[i] = tempLevel.basicChests[i];
	for (unsigned int i = 0; i < basicCoins.size(); i++) basicCoins[i] = tempLevel.basicCoins[i];
	teleportPoint = tempLevel.teleportPoint;
}

GameLevel GameLevel::operator = (const GameLevel& tempLevel)
{
	welcomeInfo = tempLevel.welcomeInfo; //upewniæ siê czy dobrze
	startingPoint = tempLevel.startingPoint;
	basicMap = tempLevel.basicMap;
	basicHero = tempLevel.basicHero;
	std::cout << "KOPIOWANY Punkt:" << startingPoint->x << startingPoint->y << std::endl;
	basicHero->MoveHeroToPoint(startingPoint);
	for (unsigned int i = 0; i < basicTeleports.size(); i++) basicTeleports[i] = tempLevel.basicTeleports[i];
	for (unsigned int i = 0; i < basicEnemies.size(); i++) basicEnemies[i] = tempLevel.basicEnemies[i];
	for (unsigned int i = 0; i < basicChests.size(); i++) basicChests[i] = tempLevel.basicChests[i];
	for (unsigned int i = 0; i < basicCoins.size(); i++) basicCoins[i] = tempLevel.basicCoins[i];
	teleportPoint = tempLevel.teleportPoint;

	return *this;
}

void GameLevel::Update()
{
	for (unsigned int i = 0; i < basicTeleports.size(); i++) basicTeleports[i]->Update();
	for (unsigned int i = 0; i < basicEnemies.size(); i++) basicEnemies[i]->Update();
	for (unsigned int i = 0; i < basicChests.size(); i++) basicChests[i]->Update();
	for (unsigned int i = 0; i < basicCoins.size(); i++) basicCoins[i]->Update();
	basicHero->Update();

	HeroCollideWithEnemy();
	HeroCollideWithChest();
	HeroCollideWithCoin();

	TextTextureManager::DrawTextTexture(
		TextTextureManager::InitTextDisplay(25, welcomeInfo, *welcomeColor));
}

void GameLevel::Render()
{
	basicMap->DrawMap();
	for (unsigned int i = 0; i < basicTeleports.size(); i++) basicTeleports[i]->Render();
	for (unsigned int i = 0; i < basicEnemies.size(); i++) basicEnemies[i]->Render();
	for (unsigned int i = 0; i < basicChests.size(); i++) basicChests[i]->Render();
	for (unsigned int i = 0; i < basicCoins.size(); i++) basicCoins[i]->Render();
	basicHero->Render();

	TextTextureManager::DrawTextTexture(
		TextTextureManager::InitTextDisplay(25, welcomeInfo, *welcomeColor));
}

void GameLevel::HeroCollideWithEnemy()
{
	for (unsigned int i = 0; i < basicEnemies.size(); i++)
	{
		if (abs(basicHero->GetDestRect().x - basicEnemies[i]->GetDestRect().x) < 32)
		{
			if (abs(basicHero->GetDestRect().y - basicEnemies[i]->GetDestRect().y) < 32)
			{
				//std::cout << "Collision with Enemy! ENGAGE!" << std::endl;
				SDL_Delay(10);
				if (basicHero->Strength > 10)
				{
					gameObjective.ScorePoints = gameObjective.ScorePoints + 1000;
					basicEnemies.erase(basicEnemies.begin() + i); i--;
				}
				else
				{
					gameObjective.HeroHealthPoints = gameObjective.HeroHealthPoints - 1;
					gameObjective.CurrentScorePoints();
				}

			}
		}
	}
}

void GameLevel::HeroCollideWithChest()
{
	for (unsigned int i = 0; i < basicChests.size(); i++)
	{
		if (abs(basicHero->GetDestRect().x - basicChests[i]->GetDestRect().x) < 32)
		{
			if (abs(basicHero->GetDestRect().y - basicChests[i]->GetDestRect().y) < 32)
			{
				//SDL_Texture* isTexture = ImageTextureManager::LoadTexture("Textures/WoodenChest.png");
				//&& basicChests[i]->objTexture == isTexture
				if (basicHero->cordsOfObject.input == 'f')
				{
					//std::cout << "Chest has been collected!" << std::endl;
					basicChests[i]->objTexture = ImageTextureManager::LoadTexture("Textures/WoodenChest_Open.png");
					SDL_Delay(10);

					gameObjective.ScorePoints = gameObjective.ScorePoints + 100;
					gameObjective.CollectedChests++;
					gameObjective.CurrentScorePoints();

					int r = rand() % 3;
					switch (r)
					{
					case 0:
						basicHero->Agility++;
						break;

					case 1:
						basicHero->Strength++;
						break;

					case 2:
						basicHero->Intelligence++;
						break;

					default:
						break;
					}
					
					basicHero->CurrentStatistics();
					basicHero->cordsOfObject.input = NULL;
				}
			}
		}
	}
}

void GameLevel::HeroCollideWithCoin()
{
	for (unsigned int i = 0; i < basicCoins.size(); i++)
	{
		if (abs(basicHero->GetDestRect().x - basicCoins[i]->GetDestRect().x) < 20)
		{
			if (abs(basicHero->GetDestRect().y - basicCoins[i]->GetDestRect().y) < 20)
			{
				std::cout << "Coin has been collected!" << std::endl;
				SDL_Delay(10);
				gameObjective.ScorePoints = gameObjective.ScorePoints + 10;
				gameObjective.CollectedCoins++;
				gameObjective.CurrentScorePoints();

				basicCoins.erase(basicCoins.begin() + i); i--;
			}
		}
	}
}