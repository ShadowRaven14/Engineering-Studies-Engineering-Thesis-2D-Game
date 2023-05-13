/*Klasa skupia wszystkie dost�pne poziomy i nimi zarz�dza. 
Tutaj zachodzie prze��czanie mi�dzy poszczeg�lnymi poziomami.*/

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

	void HeroCollideWithTeleport();
	void HeroCollideWithChest();
	void HeroCollideWithPotion();
	void HeroCollideWithCoin();
	void HeroCollideWithEnemy();

	void HandleTextUpdate();
	void HandleTextRender();

private:
	TextObject* textHealthPointsObject;
	TextObject* textScorePointsObject;
	TextObject* textStrengthObject;
	TextObject* textAgilityObject;
	TextObject* textIntelligenceObject;
	HeroObject* mainHero;
	short currentLevelID;
	std::vector <GameLevel*> basicGameLevels;
};

