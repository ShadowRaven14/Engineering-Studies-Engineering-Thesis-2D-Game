/*Klasa skupia wszystkie dostêpne poziomy i nimi zarz¹dza. 
Tutaj zachodzie prze³¹czanie miêdzy poszczególnymi poziomami.*/

#pragma once
#include "GameLevel.h"

class GameLevelManager
{
public:
	GameLevelManager();
	~GameLevelManager();
	void Update(); //Aktualizacja
	void Render(); //Renderowanie

	Point TranslatePoint(SDL_Rect currentPoint);
	void ChangeCurrentLevel(GameLevel* newLevel); //Zmiana obecnego poziomu
	void HeroCollideWithCoin();
	void HeroCollideWithChest();
	void HeroCollideWithEnemy();
	void HeroCollideWithTeleport();

private:
	HeroObject* mainHero;
	GameLevel* startLevel, * firstLevel, * secondLevel;
	GameLevel* currentLevel;
	short currentLevelID;
};

