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
	void ChangeLevel(GameLevel* newLevel); //Zmiana obecnego punktu
	void HeroCollideWithTeleport();
	//void ChangeTeleportPoint(Point newPoint); //Zmiana obecnego punktu

private:
	GameLevel *basicLevel, *secondLevel, *thirdLevel;
	GameLevel* currentLevel;
	short currentLevelID;
};

