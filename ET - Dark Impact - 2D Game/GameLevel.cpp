#include "GameLevel.h"

GameLevel::GameLevel(std::string bnMap, Point* bnStart, const char* bnHero, const char* bnTel,
	const char* bnEnemy, const char* bnChest, const char* bnCoin, Point* bnTeleport)
{
	basicMap = new BackgroundMap(bnMap);
	startingPoint = bnStart;
	basicHero = new HeroObject(bnHero, startingPoint);

	//Dodanie elementów do wektora basicEnemies
	TeleportObject* basicTeleport1 = new TeleportObject(bnTel, 64, 640, true, 0, 0);
	TeleportObject* basicTeleport2 = new TeleportObject(bnTel, 160, 160, true, 1, 1);
	TeleportObject* basicTeleport3 = new TeleportObject(bnTel, 640, 64, true, 2, 2);
	basicTeleports.push_back(basicTeleport1);
	basicTeleports.push_back(basicTeleport2);
	basicTeleports.push_back(basicTeleport3);

	//Dodanie elementów do wektora basicEnemies
	EnemyObject* basicEnemy1 = new EnemyObject(bnEnemy, 64, 640);
	EnemyObject* basicEnemy2 = new EnemyObject(bnEnemy, 160, 160);
	EnemyObject* basicEnemy3 = new EnemyObject(bnEnemy, 640, 64);
	basicEnemies.push_back(basicEnemy1);
	basicEnemies.push_back(basicEnemy2);
	basicEnemies.push_back(basicEnemy3);

	//Dodanie elementów do wektora basicChests
	ChestObject* basicChest1 = new ChestObject(bnChest, 160, 160);
	ChestObject* basicChest2 = new ChestObject(bnChest, 1152, 768);
	ChestObject* basicChest3 = new ChestObject(bnChest, 640, 400);
	ChestObject* basicChest4 = new ChestObject(bnChest);
	basicChests.push_back(basicChest1);
	basicChests.push_back(basicChest2);
	basicChests.push_back(basicChest3);
	basicChests.push_back(basicChest4);

	//Dodanie elementów do wektora basicCoins
	CoinObject* basicCoin1 = new CoinObject(bnCoin, 180, 160);
	CoinObject* basicCoin2 = new CoinObject(bnCoin, 1172, 768);
	CoinObject* basicCoin3 = new CoinObject(bnCoin, 660, 400);
	CoinObject* basicCoin4 = new CoinObject(bnCoin);
	basicCoins.push_back(basicCoin1);
	basicCoins.push_back(basicCoin2);
	basicCoins.push_back(basicCoin3);
	basicCoins.push_back(basicCoin4);

	teleportPoint = bnTeleport;
}

GameLevel::GameLevel(const GameLevel& tempLevel)
{
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
}

void GameLevel::Render()
{
	basicMap->DrawMap();
	for (unsigned int i = 0; i < basicTeleports.size(); i++) basicTeleports[i]->Render();
	for (unsigned int i = 0; i < basicEnemies.size(); i++) basicEnemies[i]->Render();
	for (unsigned int i = 0; i < basicChests.size(); i++) basicChests[i]->Render();
	for (unsigned int i = 0; i < basicCoins.size(); i++) basicCoins[i]->Render();
	basicHero->Render();
}

void GameLevel::HeroCollideWithEnemy()
{
	for (unsigned int i = 0; i < basicEnemies.size(); i++)
	{
		if (abs(basicHero->GetDestRect().x - basicEnemies[i]->GetDestRect().x) < 30)
		{
			if (abs(basicHero->GetDestRect().y - basicEnemies[i]->GetDestRect().y) < 30)
			{
				std::cout << "Collision with Enemy! ENGAGE!" << std::endl;
				SDL_Delay(10);
				gameObjective.HeroHealthPoints = gameObjective.HeroHealthPoints - 1;
				gameObjective.CurrentScorePoints();
			}
		}
	}
}

void GameLevel::HeroCollideWithChest()
{
	for (unsigned int i = 0; i < basicChests.size(); i++)
	{
		if (abs(basicHero->GetDestRect().x - basicChests[i]->GetDestRect().x) < 30)
		{
			if (abs(basicHero->GetDestRect().y - basicChests[i]->GetDestRect().y) < 30)
			{
				//SDL_Texture* isTexture = TextureManager::LoadTexture("Textures/WoodenChest.png");
				//if (basicChests[i]->objTexture == isTexture)
				//{
					std::cout << "Chest has been collected!" << std::endl;
					basicChests[i]->objTexture = TextureManager::LoadTexture("Textures/WoodenChest_Open.png");
					SDL_Delay(10);
					gameObjective.ScorePoints = gameObjective.ScorePoints + 100;
					gameObjective.CollectedChests++;
					gameObjective.CurrentScorePoints();
				//}
			}
		}
	}
}

void GameLevel::HeroCollideWithCoin()
{
	for (unsigned int i = 0; i < basicCoins.size(); i++)
	{
		if (abs(basicHero->GetDestRect().x - basicCoins[i]->GetDestRect().x) < 30)
		{
			if (abs(basicHero->GetDestRect().y - basicCoins[i]->GetDestRect().y) < 30)
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