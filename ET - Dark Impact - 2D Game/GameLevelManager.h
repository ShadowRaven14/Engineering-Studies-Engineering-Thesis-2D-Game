/*Klasa skupia wszystkie dostępne poziomy i nimi zarządza. 
Tutaj zachodzie przełączanie między poszczególnymi poziomami.*/

#pragma once
#include "GameLevel.h"
#include "TextObject.h"
#include "MainHeroObject.h"

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
	short currentLevelID;
	std::vector <GameLevel*> basicGameLevels;
	MainHeroObject* mainHero;
	
	TextObject* textHealthPointsObject;
	TextObject* textScorePointsObject;

	TextObject* textStrengthObject;
	TextObject* textAgilityObject;
	TextObject* textIntelligenceObject;

	TextObject* textMageRelationsObject;
	TextObject* textSentinelsRelationsObject;
};

