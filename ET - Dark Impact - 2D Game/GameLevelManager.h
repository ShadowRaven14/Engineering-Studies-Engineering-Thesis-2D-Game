/*Klasa skupia wszystkie dostêpne poziomy i nimi zarz¹dza. 
Tutaj zachodzie prze³¹czanie miêdzy poszczególnymi poziomami.*/

#pragma once
#include "GameLevel.h"
#include "TextObject.h"
#include "MainHeroObject.h"

class GameLevelManager
{
public:
	//Podstawowe
	GameLevelManager(); //Konstruktor
	~GameLevelManager(); //Destruktor
	void Update(); //Aktualizacja
	void Render(); //Renderowanie

	//Zaawansowane
	void HandleHeroMovement();
	const Point distanceToEdge = Point(320, 224);

	Point TranslatePoint(SDL_Rect currentPoint);
	void ChangeHeroTexture_DamageOrHeal(bool damage);

	void HeroCollide_With_Teleport();
	void HeroCollide_With_Chest();

	void HeroCollide_With_AppleItem();
	void HeroCollide_With_CoinItem();
	void HeroCollide_With_PotionItem();
	
	void HeroCollide_With_MageEnemy();
	void HeroCollide_With_SentinelEnemy();

	void HandleTextUpdate();
	void HandleTextRender();

private:
	//Zaawansowane
	short currentLevelID;
	std::vector <GameLevel*> basicGameLevels; //tablica poziomów gry
	MainHeroObject* mainHero;
	
	TextObject* textHealthPointsObject = NULL;
	TextObject* textScorePointsObject = NULL;

	TextObject* textStrengthObject = NULL;
	TextObject* textAgilityObject = NULL;
	TextObject* textIntelligenceObject = NULL;

	TextObject* textMageRelationsObject = NULL;
	TextObject* textSentinelsRelationsObject = NULL;
};

