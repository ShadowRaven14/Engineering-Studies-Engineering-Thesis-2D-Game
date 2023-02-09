/*Klasa skupia wszystkie dost�pne poziomy i nimi zarz�dza. 
Tutaj zachodzie prze��czanie mi�dzy poszczeg�lnymi poziomami.*/

#pragma once
#include "GameLevel.h"
#include "HeroObject.h"
//#include "HeroStatistics.h"

class GameLevelManager
{
public:
	GameLevelManager();
	~GameLevelManager();
	void Update(); //Aktualizacja
	void Render(); //Renderowanie

	void HandleHeroMovement();
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

