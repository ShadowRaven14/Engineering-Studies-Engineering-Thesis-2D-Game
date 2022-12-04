#include "BasicGameLevel.h"

BasicGameLevel::BasicGameLevel(std::string bnMap, const char* bnHero, const char* bnEnemy, const char* bnChest, Point* bnTeleport)
{
	basicMap = new BackgroundMap(bnMap);
	basicHero = new HeroObject(bnHero, 640, 448);
	basicEnemy = new EnemyObject(bnEnemy, 32, 64);
	basicChest = new ChestObject(bnChest);
	teleportPoint = bnTeleport;
}

BasicGameLevel::BasicGameLevel(const BasicGameLevel& tempLevel)
{
	basicMap = tempLevel.basicMap;
	basicHero = tempLevel.basicHero;
	basicEnemy = tempLevel.basicEnemy;
	basicChest = tempLevel.basicChest;
	teleportPoint = tempLevel.teleportPoint;
}

void BasicGameLevel::Update()
{
	basicHero->Update();
	basicEnemy->Update();
	basicChest->Update();
	HeroCollideWithEnemy();
}

void BasicGameLevel::Render()
{
	basicMap->DrawMap();
	basicHero->Render();
	basicEnemy->Render();
	basicChest->Render();
}

void BasicGameLevel::HeroCollideWithEnemy()
{
	if (abs(basicHero->GetDestRect().x - basicEnemy->GetDestRect().x) < 30)
	{
		if (abs(basicHero->GetDestRect().y - basicEnemy->GetDestRect().y) < 30)
		{
			std::cout << "WALKA!" << std::endl;
			SDL_Delay(1000);
		}
	}
}