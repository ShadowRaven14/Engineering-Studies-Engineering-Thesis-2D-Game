/*Klasa skupia wszystkie dostępne poziomy i nimi zarządza. 
Tutaj zachodzie przełączanie między poszczególnymi poziomami.*/

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
	void HeroCollideWithTeleport();

private:
	GameLevel *basicLevel, *secondLevel, *thirdLevel;
	GameLevel *currentLevel;
	short currentLevelID;
};

