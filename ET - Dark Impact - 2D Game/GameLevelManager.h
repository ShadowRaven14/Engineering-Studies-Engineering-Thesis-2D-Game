/*Klasa skupia wszystkie dostêpne poziomy i nimi zarz¹dza. 
Tutaj zachodzie prze³¹czanie miêdzy poszczególnymi poziomami.*/

#pragma once
#include "GameLevel.h"
#include "TextObject.h"
#include "HeroObject.h"

class GameLevelManager
{
public:
	GameLevelManager();
	~GameLevelManager();
	void Update(); //Aktualizacja
	void Render(); //Renderowanie

	void HandleHeroMovement();
	const Point distanceToEdge = Point(320, 224);

	Point TranslatePoint(SDL_Rect currentPoint);

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
	short currentLevelID;
	std::vector <GameLevel*> basicGameLevels;
	HeroObject* mainHero;
	
	TextObject* textHealthPointsObject;
	TextObject* textScorePointsObject;

	TextObject* textStrengthObject;
	TextObject* textAgilityObject;
	TextObject* textIntelligenceObject;

	TextObject* textMageRelationsObject;
	TextObject* textSentinelsRelationsObject;
};

