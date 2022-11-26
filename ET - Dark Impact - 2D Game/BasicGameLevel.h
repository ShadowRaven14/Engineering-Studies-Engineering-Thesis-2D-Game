#pragma once
#include "EnemyObject.h"
#include "ChestObject.h"
#include "BackgroundMap.h"
#include "HeroObject.h"

class BasicGameLevel
{
public:
	BasicGameLevel(std::string bnMap, const char* bnHero, const char* bnEnemy, const char* bnChest);
	~BasicGameLevel();
	BackgroundMap* basicMap;
	HeroObject* basicHero;
	EnemyObject* basicEnemy;
	ChestObject* basicChest;
};

