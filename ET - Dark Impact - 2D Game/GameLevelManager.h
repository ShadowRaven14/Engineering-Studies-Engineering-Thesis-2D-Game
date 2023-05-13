/*Klasa skupia wszystkie dostêpne poziomy i nimi zarz¹dza. 
Tutaj zachodzie prze³¹czanie miêdzy poszczególnymi poziomami.*/

#pragma once
#include "GameLevel.h"
#include "HeroObject.h"
//#include "HeroObjectives.h"

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

private:
	HeroObject* mainHero;
	short currentLevelID;
	std::vector <GameLevel*> basicGameLevels;
};

