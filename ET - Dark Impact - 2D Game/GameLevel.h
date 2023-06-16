/*Klasa reprezentuje pojedynczy poziom gry.
Ka�dy poziom gry generuje w losowych miejscach i losow� ilo��: Teleport�w, Skrzy�, Jab�ek, Monet, Mikstur, Przeciwnik�w Mag�w, Przeciwnik�w Stra�nik�w. 
Klasa ta dodatkowo posiada swoje unikatowe ID, notatk�, map�. 
Identyfikator powinien by� unikatowy, rozr�nia on poziomy - b�dzie wykorzystywane przez klas� GameLevelManager (Manager Poziom�w).
Notatka sk�ada si� z tekstu, koloru i czcionki - produkowana b�dzie przez klasy TextObject i FontTextureManager.
Mapa stanowi podstaw� poziomu - produkowana jest przez klas� BackgroundMap*/

#pragma once
#include "Point.h"
#include "BackgroundMap.h"

#include "TeleportObject.h"
#include "ChestObject.h"

#include "AppleItemObject.h"
#include "CoinObject.h"
#include "PotionObject.h"

#include "_EnemyObject.h"
#include "EnemySentinelObject.h"
#include "EnemyMageObject.h"

#include <vector>
#include "ImageTextureManager.h"
#include "FontTextureManager.h"



class GameLevel
{
public:
	GameLevel(); //Konstruktor
	GameLevel(short bnID, const char* bnInfo, SDL_Color* bnColor, std::string bnMap, Point* bnStart); //Konstruktor
	GameLevel(short bnID, const char* bnInfo, SDL_Color* bnColor, std::string bnMap, Point* bnStart,
		const char* bnHero, const char* bnTel, const char* bnEnemy, const char* bnChest, 
		const char* bnCoin); //Konstruktor
	GameLevel(const GameLevel &tempLevel); //Konstruktor
	~GameLevel(); //Destruktor
	GameLevel& operator= (const GameLevel& tempLevel); //Przeci��enie operatora
	GameLevel& operator= (GameLevel* tempLevel); //Przeci��enie operatora
	void Update(); //Aktualizacja
	void Render(); //Renderowanie

	void MoveAllObjectsBy(int x, int y); //Poruszenie wszystkich GameObjects

	unsigned short levelID;
	const char* info;
	SDL_Color* color;
	SDL_Texture* fontTexture;
	Point* startingPoint;
	BackgroundMap* basicMap;

	std::vector <TeleportObject*> basicTeleports;
	std::vector <ChestObject*> basicChests;

	std::vector <AppleItemObject*> basicItemApples;
	std::vector <CoinObject*> basicItemCoins;
	std::vector <PotionObject*> basicItemPotions;

	std::vector <EnemyMageObject*> basicMageEnemies;
	std::vector <EnemySentinelObject*> basicSentinelEnemies;
};

