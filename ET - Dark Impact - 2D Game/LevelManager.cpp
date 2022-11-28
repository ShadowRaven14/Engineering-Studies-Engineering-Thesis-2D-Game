#include "LevelManager.h"

LevelManager::LevelManager()
{
	basicLevel = new BasicGameLevel(
		"Maps/StartingMap.txt",
		"Assets/crow1.png",
		"Assets/apple_golden1.png",
		"Assets/chest1.png");

	secondLevel = new BasicGameLevel(
		"Maps/Test.txt",
		"Assets/crow1.png",
		"Assets/apple_golden2.png",
		"Assets/chest1.png");

	thirdLevel = new BasicGameLevel(
		"Maps/Test.txt",
		"Assets/crow1.png",
		"Assets/apple_golden2.png",
		"Assets/chest1.png");

	currentLevel = basicLevel;
}

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
	if (currentPoint.x == currentLevel->teleportPoint.x && currentPoint.y == currentLevel->teleportPoint.y)
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

		//currentLevel->Update();
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

void LevelManager::ChangeLevel(BasicGameLevel *newLevel)
{
	currentLevel = newLevel;
}