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

	void TeleportToNewMap(Point currentPoint); //Zmiana bieżącej mapy
	void ChangeTeleportPoint(Point newPoint); //Zmiana obecnego punktu
	void HeroCollideWithTeleport();
	Point TranslatePoint(SDL_Rect currentPoint);
	void ChangeLevel(GameLevel *newLevel); //Zmiana obecnego punktu

	

private:
	GameLevel *basicLevel, *secondLevel, *thirdLevel;
	GameLevel* currentLevel;
	short currentLevelID;
};

