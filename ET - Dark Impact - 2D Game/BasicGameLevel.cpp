#include "BasicGameLevel.h"

BasicGameLevel::BasicGameLevel(std::string bnMap, const char* bnHero, const char* bnEnemy, const char* bnChest, Point* bnTeleport)
{
	basicMap = new BackgroundMap(bnMap);
	basicHero = new HeroObject(bnHero, 640, 448);

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

	teleportPoint = bnTeleport;
}

BasicGameLevel::BasicGameLevel(const BasicGameLevel& tempLevel)
{
	basicMap = tempLevel.basicMap;
	basicHero = tempLevel.basicHero;
	for (unsigned int i = 0; i < basicEnemies.size(); i++) basicEnemies[i] = tempLevel.basicEnemies[i];
	for (unsigned int i = 0; i < basicEnemies.size(); i++) basicChests[i] = tempLevel.basicChests[i];
	teleportPoint = tempLevel.teleportPoint;
}

void BasicGameLevel::Update()
{
	for (unsigned int i = 0; i < basicEnemies.size(); i++) basicEnemies[i]->Update();
	for (unsigned int i = 0; i < basicChests.size(); i++) basicChests[i]->Update();
	basicHero->Update();

	HeroCollideWithEnemy();
	HeroCollideWithChest();
}

void BasicGameLevel::Render()
{
	basicMap->DrawMap();
	for (unsigned int i = 0; i < basicEnemies.size(); i++) basicEnemies[i]->Render();
	for (unsigned int i = 0; i < basicChests.size(); i++) basicChests[i]->Render();
	basicHero->Render();
}

void BasicGameLevel::HeroCollideWithEnemy()
{
	for (unsigned int i = 0; i < basicEnemies.size(); i++)
	{
		if (abs(basicHero->GetDestRect().x - basicEnemies[i]->GetDestRect().x) < 30)
		{
			if (abs(basicHero->GetDestRect().y - basicEnemies[i]->GetDestRect().y) < 30)
			{
				std::cout << "WALKA!" << std::endl;
				SDL_Delay(10);
				gameObjective.ScorePoints = gameObjective.ScorePoints - 20;
				std::cout << "ScorePoints: " << gameObjective.ScorePoints << std::endl;
			}
		}
	}
}

void BasicGameLevel::HeroCollideWithChest()
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
					std::cout << "Skrzynia zebrana!" << std::endl;
					basicChests[i]->objTexture = TextureManager::LoadTexture("Textures/WoodenChest_Open.png");
					SDL_Delay(10);
					gameObjective.ScorePoints = gameObjective.ScorePoints + 100;
					std::cout << "ScorePoints: " << gameObjective.ScorePoints << std::endl;
					gameObjective.CollectedChests++;
					std::cout << "ScorePoints: " << gameObjective.CollectedChests << std::endl;
				//}
			}
		}
	}
}