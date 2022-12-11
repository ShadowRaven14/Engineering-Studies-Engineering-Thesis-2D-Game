#include "BasicGameLevel.h"

BasicGameLevel::BasicGameLevel(std::string bnMap, const char* bnHero, const char* bnEnemy, const char* bnChest, Point* bnTeleport)
{
	basicMap = new BackgroundMap(bnMap);
	basicHero = new HeroObject(bnHero, 640, 448);
	teleportPoint = bnTeleport;

	basicEnemy = new EnemyObject(bnEnemy, 64, 640);
	basicEnemies.push_back(basicEnemy);
	basicEnemy = new EnemyObject(bnEnemy, 160, 160);
	basicEnemies.push_back(basicEnemy);
	basicEnemy = new EnemyObject(bnEnemy, 640, 64);
	basicEnemies.push_back(basicEnemy);

	basicChest = new ChestObject(bnChest, 160, 160);
	basicChests.push_back(basicChest);
	basicChest = new ChestObject(bnChest, 1152, 768);
	basicChests.push_back(basicChest);
	basicChest = new ChestObject(bnChest);
	basicChests.push_back(basicChest);
}

BasicGameLevel::BasicGameLevel(const BasicGameLevel& tempLevel)
{
	basicMap = tempLevel.basicMap;
	basicHero = tempLevel.basicHero;
	basicEnemy = tempLevel.basicEnemy;
	for (size_t i = 0; i < basicEnemies.size(); i++) basicEnemies[i] = tempLevel.basicEnemies[i];
	basicChest = tempLevel.basicChest;
	for (size_t i = 0; i < basicEnemies.size(); i++) basicChests[i] = tempLevel.basicChests[i];
	teleportPoint = tempLevel.teleportPoint;
}

void BasicGameLevel::Update()
{
	basicHero->Update();
	//basicEnemy->Update();
	for (size_t i = 0; i < basicEnemies.size(); i++) basicEnemies[i]->Update();
	//basicChest->Update();
	for (size_t i = 0; i < basicChests.size(); i++) basicChests[i]->Update();
	HeroCollideWithEnemy();
}

void BasicGameLevel::Render()
{
	basicMap->DrawMap();
	basicHero->Render();
	//basicEnemy->Render();
	for (size_t i = 0; i < basicEnemies.size(); i++) basicEnemies[i]->Render();
	//basicChest->Render();
	for (size_t i = 0; i < basicChests.size(); i++) basicChests[i]->Render();
}

void BasicGameLevel::HeroCollideWithEnemy()
{
	if (abs(basicHero->GetDestRect().x - basicEnemy->GetDestRect().x) < 30)
	{
		if (abs(basicHero->GetDestRect().y - basicEnemy->GetDestRect().y) < 30)
		{
			std::cout << "WALKA!" << std::endl;
			SDL_Delay(10);
		}
	}
}