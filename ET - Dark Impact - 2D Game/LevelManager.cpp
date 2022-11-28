#include "LevelManager.h"

void LevelManager::Update()
{
	TeleportToNewMap(TranslatePoint(currentLevel->basicHero->GetDestRect()));
}

void LevelManager::Render()
{
	basicLevel->Render();
	secondLevel->Render();
	thirdLevel->Render();
}

void LevelManager::TeleportToNewMap(Point currentPoint)
{
	if (currentPoint.x == teleportPoint.x && currentPoint.y == teleportPoint.y)
	{
		short s = 0;

		SDL_Rect newRect = basicLevel->basicHero->GetDestRect();
		if (newRect.x == 50) s = 1;

		switch (s)
		{
		case 0:
			basicLevel->Update();
			break;

		case 1:
			secondLevel->Update();
			break;

		case 2:
			thirdLevel->Update();
			break;

		default:
			basicLevel->Update();
			break;
		}
	}
}

Point LevelManager::TranslatePoint(SDL_Rect currentPoint)
{
	//SDL_Rect currentPoint = currentLevel->basicHero->GetDestRect();
	Point newcurrentPoint;
	newcurrentPoint.x = currentPoint.x;
	newcurrentPoint.y = currentPoint.y;

	return newcurrentPoint;
}