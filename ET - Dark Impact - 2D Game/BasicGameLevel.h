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
	void Update(); //Aktualizacja
	void Render(); //Renderowanie
	void TeleportToNewMap(); //Zmiana bie¿¹cej mapy

	BackgroundMap* basicMap;
	HeroObject* basicHero;
	EnemyObject* basicEnemy;
	ChestObject* basicChest;
};

