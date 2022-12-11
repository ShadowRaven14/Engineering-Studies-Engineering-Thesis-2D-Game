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
	ChestObject* basicChest3 = new ChestObject(bnChest);
	basicChests.push_back(basicChest1);
	basicChests.push_back(basicChest2);
	basicChests.push_back(basicChest3);

	teleportPoint = bnTeleport;
}

BasicGameLevel::BasicGameLevel(const BasicGameLevel& tempLevel)
{
	basicMap = tempLevel.basicMap;
	basicHero = tempLevel.basicHero;
	for (size_t i = 0; i < basicEnemies.size(); i++) basicEnemies[i] = tempLevel.basicEnemies[i];
	for (size_t i = 0; i < basicEnemies.size(); i++) basicChests[i] = tempLevel.basicChests[i];
	teleportPoint = tempLevel.teleportPoint;
}

void BasicGameLevel::Update()
{
	basicHero->Update();
	for (size_t i = 0; i < basicEnemies.size(); i++) basicEnemies[i]->Update();
	for (size_t i = 0; i < basicChests.size(); i++) basicChests[i]->Update();
	HeroCollideWithEnemy();
}

void BasicGameLevel::Render()
{
	basicMap->DrawMap();
	basicHero->Render();
	for (size_t i = 0; i < basicEnemies.size(); i++) basicEnemies[i]->Render();
	for (size_t i = 0; i < basicChests.size(); i++) basicChests[i]->Render();
}

void BasicGameLevel::HeroCollideWithEnemy()
{
	for (size_t i = 0; i < basicEnemies.size(); i++)
	{
		if (abs(basicHero->GetDestRect().x - basicEnemies[i]->GetDestRect().x) < 30)
		{
			if (abs(basicHero->GetDestRect().y - basicEnemies[i]->GetDestRect().y) < 30)
			{
				std::cout << "WALKA!" << std::endl;
				SDL_Delay(10);
			}
		}
	}
}