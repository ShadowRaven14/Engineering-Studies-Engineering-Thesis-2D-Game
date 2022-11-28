#pragma once
#include "BasicGameLevel.h"

class LevelManager
{
public:
	LevelManager();
	~LevelManager();
	void Update(); //Aktualizacja
	void Render(); //Renderowanie

	void TeleportToNewMap(Point currentPoint); //Zmiana bie¿¹cej mapy
	void ChangeTeleportPoint(Point newPoint); //Zmiana obecnego punktu
	Point TranslatePoint(SDL_Rect currentPoint);
	void ChangeLevel(BasicGameLevel *newLevel); //Zmiana obecnego punktu

private:
	BasicGameLevel *basicLevel, *secondLevel, *thirdLevel;
	BasicGameLevel* currentLevel;
};

