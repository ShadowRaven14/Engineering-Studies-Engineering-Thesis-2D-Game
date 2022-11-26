#include "BasicGameLevel.h"

BasicGameLevel::BasicGameLevel(std::string bnMap, const char* bnHero, const char* bnEnemy, const char* bnChest)
{
	basicMap = new BackgroundMap(bnMap);
	basicHero = new HeroObject(bnHero, 640, 448);
	basicEnemy = new EnemyObject(bnEnemy, 40, 48);
	basicChest = new ChestObject(bnChest);
}