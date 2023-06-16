/*Klasa reprezentuje pojedynczy poziom gry.
Ka¿dy poziom gry generuje w losowych miejscach i losow¹ iloœæ: Teleportów, Skrzyñ, Jab³ek, Monet, Mikstur, Przeciwników Magów, Przeciwników Stra¿ników. 
Klasa ta dodatkowo posiada swoje unikatowe ID, notatkê, mapê. 
Identyfikator powinien byæ unikatowy, rozró¿nia on poziomy - bêdzie wykorzystywane przez klasê GameLevelManager (Manager Poziomów).
Notatka sk³ada siê z tekstu, koloru i czcionki - produkowana bêdzie przez klasy TextObject i FontTextureManager.
Mapa stanowi podstawê poziomu - produkowana jest przez klasê BackgroundMap*/

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
	GameLevel& operator= (const GameLevel& tempLevel); //Przeci¹¿enie operatora
	GameLevel& operator= (GameLevel* tempLevel); //Przeci¹¿enie operatora
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

