#include "LevelManager.h"

LevelManager::LevelManager()
{
	basicLevel = new BasicGameLevel(
		"Maps/StartingMap.txt",
		"Assets/crow1.png",
		"Assets/apple_golden1.png",
		"Assets/chest1.png",
		new Point(672, 480));

	secondLevel = new BasicGameLevel(
		"Maps/Test.txt",
		"Assets/crow1.png",
		"Assets/apple_golden2.png",
		"Assets/chest1.png",
		new Point(672, 480));

	thirdLevel = new BasicGameLevel(
		"Maps/Test.txt",
		"Assets/crow1.png",
		"Assets/apple_golden2.png",
		"Assets/chest1.png",
		new Point(672, 480));

	currentLevel = basicLevel;
}

void LevelManager::Update()
{
	TeleportToNewMap(TranslatePoint(currentLevel->basicHero->GetDestRect()));
}

void LevelManager::Render()
{
	thirdLevel->Render();
	secondLevel->Render();
	basicLevel->Render();
}

void LevelManager::TeleportToNewMap(Point currentPoint)
{
	//currentPoint jest to pozycja bohatera

	if (currentPoint.x == currentLevel->teleportPoint->x && currentPoint.y == currentLevel->teleportPoint->y)
	{
		short s = 1;
		//SDL_Rect newRect = basicLevel->basicHero->GetDestRect();
		std::cout << currentPoint.x << " " << currentPoint.y << std::endl;
		//if (newRect.x == 672) s = 1;

		switch (s)
		{
		case 0:
			currentLevel = basicLevel;
			break;

		case 1:
			currentLevel = secondLevel;
			break;

		case 2:
			currentLevel = thirdLevel;
			break;

		default:
			currentLevel = basicLevel;
			break;
		}
	}
	currentLevel->Update();
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