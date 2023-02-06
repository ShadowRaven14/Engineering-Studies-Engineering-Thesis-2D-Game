/*Klasa reprezentuje pojedynczy poziom gry.*/

#pragma once
#include "Point.h"
#include "BackgroundMap.h"

#include "TeleportObject.h"
#include "ChestObject.h"
#include "PotionObject.h"
#include "CoinObject.h"
#include "EnemyObject.h"

#include <vector>
#include "ImageTextureManager.h"
#include "FontTextureManager.h"



class GameLevel
{
public:
	GameLevel();
	GameLevel(short bnID, const char* bnInfo, SDL_Color* bnColor, std::string bnMap, Point* bnStart);
	GameLevel(short bnID, const char* bnInfo, SDL_Color* bnColor, std::string bnMap, Point* bnStart,
		const char* bnHero, const char* bnTel, const char* bnEnemy, const char* bnChest, 
		const char* bnCoin);
	GameLevel(const GameLevel &tempLevel);
	~GameLevel();
	GameLevel& operator= (const GameLevel& tempLevel); //Przeci¹¿enie operatora
	GameLevel& operator= (GameLevel* tempLevel); //Przeci¹¿enie operatora
	void Update(); //Aktualizacja
	void Render(); //Renderowanie

	unsigned short levelID;
	const char* welcomeInfo;
	SDL_Color* welcomeColor;
	Point* startingPoint;
	BackgroundMap* basicMap;
	std::vector <TeleportObject*> basicTeleports;
	std::vector <ChestObject*> basicChests;
	std::vector <PotionObject*> basicPotions;
	std::vector <CoinObject*> basicCoins;
	std::vector <EnemyObject*> basicEnemies;
};

