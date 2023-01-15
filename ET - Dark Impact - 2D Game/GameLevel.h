/*Klasa reprezentuje pojedynczy poziom gry.*/

#pragma once
#include "Point.h"
#include "BackgroundMap.h"
#include "HeroObject.h"
#include "TeleportObject.h"
#include "EnemyObject.h"
#include "ChestObject.h"
#include "CoinObject.h"
#include "GameObjective.h"
#include <vector>
#include "ImageTextureManager.h"
#include "TextTextureManager.h"


class GameLevel
{
public:
	GameLevel(const char* bnInfo, SDL_Color* bnColor, std::string bnMap, Point* bnStart, const char* bnHero, const char* bnTel,
		const char* bnEnemy, const char* bnChest, const char* bnCoin, Point* bnTeleport);
	GameLevel(const GameLevel &tempLevel);
	~GameLevel();
	GameLevel operator=(const GameLevel& tempLevel);
	void Update(); //Aktualizacja
	void Render(); //Renderowanie

	GameObjective gameObjective;

	const char* welcomeInfo;
	SDL_Color* welcomeColor;
	Point* startingPoint;
	BackgroundMap *basicMap;
	HeroObject *basicHero;
	std::vector <TeleportObject*> basicTeleports;
	std::vector <EnemyObject*> basicEnemies;
	std::vector <ChestObject*> basicChests;
	std::vector <CoinObject*> basicCoins;
	Point *teleportPoint;

	void HeroCollideWithEnemy();
	void HeroCollideWithChest();
	void HeroCollideWithCoin();
};

