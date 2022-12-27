/*Klasa reprezentuje pojedynczy poziom gry.*/

#pragma once
#include "Point.h"
#include "BackgroundMap.h"
#include "HeroObject.h"
#include "EnemyObject.h"
#include "ChestObject.h"
#include "CoinObject.h"
#include "GameObjective.h"
#include <vector>


class GameLevel
{
public:
	GameLevel(std::string bnMap, Point* bnStart, const char* bnHero, 
		const char* bnEnemy, const char* bnChest, const char* bnCoin, Point* bnTeleport);
	GameLevel(const GameLevel &tempLevel);
	~GameLevel();
	GameLevel operator=(const GameLevel& tempLevel);
	void Update(); //Aktualizacja
	void Render(); //Renderowanie

	GameObjective gameObjective;

	Point* startingPoint;
	BackgroundMap *basicMap;
	HeroObject *basicHero;
	std::vector <EnemyObject*> basicEnemies;
	std::vector <ChestObject*> basicChests;
	std::vector <CoinObject*> basicCoins;
	Point *teleportPoint;

	void HeroCollideWithEnemy();
	void HeroCollideWithChest();
	void HeroCollideWithCoin();
};

