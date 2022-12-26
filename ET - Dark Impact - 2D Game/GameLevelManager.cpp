#include "GameLevelManager.h"

GameLevelManager::GameLevelManager()
{
	basicLevel = new GameLevel(
		"Maps/StartingMap.txt",
		new Point(640, 448),
		"Textures/ElvenTracker.png",
		"Textures/HumanMage.png",
		"Textures/WoodenChest.png",
		new Point(672, 480));

	secondLevel = new GameLevel(
		"Maps/Test.txt",
		new Point(640, 448),
		"Textures/ElvenTracker.png",
		"Textures/HumanMage.png",
		"Textures/WoodenChest.png",
		new Point(672, 480));

	thirdLevel = new GameLevel(
		"Maps/Exported.txt",
		new Point(640, 448),
		"Textures/ElvenTracker.png",
		"Textures/HumanMage.png",
		"Textures/WoodenChest.png",
		new Point(672, 480));

	ChangeLevel(basicLevel);
	currentLevelID = 0;
}

void GameLevelManager::Update()
{
	TeleportToNewMap(TranslatePoint(currentLevel->basicHero->GetDestRect()));
	currentLevel->Update();
}

void GameLevelManager::Render()
{
	currentLevel->Render();
}

void GameLevelManager::TeleportToNewMap(Point currentPoint)
{
	//currentPoint jest to pozycja bohatera
	if (currentPoint.x == currentLevel->teleportPoint->x && currentPoint.y == currentLevel->teleportPoint->y)
	{
		currentLevelID++;
		std::cout << currentPoint.x << " " << currentPoint.y << std::endl;
		std::cout << "ZMIANA MAPY" << std::endl;
		switch (currentLevelID)
		{
		case 0:
			ChangeLevel(basicLevel);
			break;

		case 1:
			ChangeLevel(secondLevel);
			break;

		case 2:
			ChangeLevel(thirdLevel);
			break;

		default:
			ChangeLevel(basicLevel);
			currentLevelID = 0;
			break;
		}
	}
}

Point GameLevelManager::TranslatePoint(SDL_Rect currentPoint)
{
	Point newcurrentPoint;
	newcurrentPoint.x = currentPoint.x;
	newcurrentPoint.y = currentPoint.y;

	return newcurrentPoint;
}

void GameLevelManager::ChangeLevel(GameLevel *newLevel)
{
	currentLevel = newLevel;
	currentLevel->basicHero->MoveHeroToPoint(
		new Point(
			currentLevel->startingPoint->x,
			currentLevel->startingPoint->y
		)
	);
}