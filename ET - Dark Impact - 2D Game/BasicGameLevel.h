/*Klasa reprezentuje pojedynczy poziom gry.*/

#pragma once
#include "BackgroundMap.h"
#include "EnemyObject.h"
#include "HeroObject.h"
#include "ChestObject.h"
#include "Point.h"
#include "GameObjective.h"
#include <vector>

class BasicGameLevel
{
public:
	BasicGameLevel(std::string bnMap, Point* bnStart, const char* bnHero, const char* bnEnemy, const char* bnChest, Point* bnTeleport);
	BasicGameLevel(const BasicGameLevel &tempLevel);
	BasicGameLevel operator=(const BasicGameLevel &tempLevel);
	~BasicGameLevel();
	//bool operator =(const _typ_&);
	void Update(); //Aktualizacja
	void Render(); //Renderowanie

	GameObjective gameObjective;

	Point* startingPoint;
	BackgroundMap *basicMap;
	HeroObject *basicHero;
	std::vector <EnemyObject*> basicEnemies;
	std::vector <ChestObject*> basicChests;
	Point *teleportPoint;

	void HeroCollideWithEnemy();
	void HeroCollideWithChest();
};

