#include "LevelManager.h"

LevelManager::LevelManager()
{
	basicLevel = new BasicGameLevel(
		"Maps/StartingMap.txt",
		new Point(640, 448),
		"Textures/ElvenTracker.png",
		"Textures/HumanMage.png",
		"Textures/WoodenChest.png",
		new Point(672, 480));

	secondLevel = new BasicGameLevel(
		"Maps/Test.txt",
		new Point(640, 448),
		"Textures/ElvenTracker.png",
		"Textures/HumanMage.png",
		"Textures/WoodenChest.png",
		new Point(672, 480));

	thirdLevel = new BasicGameLevel(
		"Maps/Exported.txt",
		new Point(640, 448),
		"Textures/ElvenTracker.png",
		"Textures/HumanMage.png",
		"Textures/WoodenChest.png",
		new Point(672, 480));

	currentLevel = basicLevel;
	currentLevelID = 0;
}

void LevelManager::Update()
{
	TeleportToNewMap(TranslatePoint(currentLevel->basicHero->GetDestRect()));
	currentLevel->Update();
}

void LevelManager::Render()
{
	currentLevel->Render();
}

void LevelManager::TeleportToNewMap(Point currentPoint)
{
	//currentPoint jest to pozycja bohatera
	if (currentPoint.x == currentLevel->teleportPoint->x && currentPoint.y == currentLevel->teleportPoint->y)
	{
		currentLevelID++;

		//SDL_Rect newRect = basicLevel->basicHero->GetDestRect();
		std::cout << currentPoint.x << " " << currentPoint.y << std::endl;
		//if (newRect.x == 672) s = 1;

		switch (currentLevelID)
		{
		case 0:
			currentLevel = basicLevel;
			//basicLevel->Render();
			break;

		case 1:
			currentLevel = secondLevel;
			//secondLevel->Render();
			break;

		case 2:
			currentLevel = thirdLevel;
			//thirdLevel->Render();
			break;

		default:
			currentLevel = basicLevel;
			currentLevelID = 0;
			//basicLevel->Render();
			//currentLevelID = 0;
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

void LevelManager::ChangeLevel(BasicGameLevel *newLevel)
{
	currentLevel = newLevel;
}