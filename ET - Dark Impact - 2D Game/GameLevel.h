/*Klasa reprezentuje pojedynczy poziom gry.*/

#pragma once
#include "Point.h"
#include "BackgroundMap.h"

#include "TeleportObject.h"
#include "ChestObject.h"

#include "AppleItemObject.h"
#include "CoinObject.h"
#include "PotionObject.h"

#include "EnemyObject.h"
#include "EnemySentinelObject.h"
#include "EnemyMageObject.h"

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
	GameLevel& operator= (const GameLevel& tempLevel); //Przeciążenie operatora
	GameLevel& operator= (GameLevel* tempLevel); //Przeciążenie operatora
	void Update(); //Aktualizacja
	void Render(); //Renderowanie

	void MoveAllObjectsBy(int x, int y);

	unsigned short levelID;
	const char* info;
	SDL_Color* color;
	SDL_Texture* fontTexture;
	Point* startingPoint;
	BackgroundMap* basicMap;

	std::vector <TeleportObject*> basicTeleports;
	std::vector <ChestObject*> basicChests;

	std::vector <AppleItemObject*> basicItemApples;
	std::vector <CoinObject*> basicCoins;
	std::vector <PotionObject*> basicPotions;

	std::vector <EnemyObject*> basicEnemies;
	std::vector <EnemyMageObject*> basicMageEnemies;
	std::vector <EnemySentinelObject*> basicSentinelEnemies;
};

