/*Klasa skupia wszystkie dost�pne poziomy i nimi zarz�dza. 
Tutaj zachodzie prze��czanie mi�dzy poszczeg�lnymi poziomami.*/

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
	void ChangeLevel(GameLevel* newLevel); //Zmiana obecnego punktu
	void HeroCollideWithTeleport();

private:
	GameLevel *basicLevel, *secondLevel, *thirdLevel;
	GameLevel* currentLevel;
	short currentLevelID;
};

