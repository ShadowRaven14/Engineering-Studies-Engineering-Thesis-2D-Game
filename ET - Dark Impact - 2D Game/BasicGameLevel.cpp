#include "BasicGameLevel.h"

BasicGameLevel::BasicGameLevel(std::string bnMap, const char* bnHero, const char* bnEnemy, const char* bnChest)
{
	basicMap = new BackgroundMap(bnMap);
	basicHero = new HeroObject(bnHero, 640, 448);
	basicEnemy = new EnemyObject(bnEnemy, 40, 48);
	basicChest = new ChestObject(bnChest);
}

void BasicGameLevel::Update()
{
	basicHero->Update();
	basicEnemy->Update();
	basicChest->Update();
}

void BasicGameLevel::Render()
{
	basicMap->DrawMap();
	basicHero->Render();
	basicEnemy->Render();
	basicChest->Render();
}

void BasicGameLevel::TeleportToNewMap()
{
	//SDL_Rect rect = basicHero->GetDestRect;
	//if(destRect.x == 100)

	//basicHero->
	//basicHero->destRect.x = 100;
	//basicHero->destRect.y = 100;
}