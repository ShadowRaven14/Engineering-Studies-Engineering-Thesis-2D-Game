#include "GameLevelManager.h"

GameLevelManager::GameLevelManager()
{
	basicLevel = new GameLevel(
		"Maps/StartingMap.txt",
		new Point(640, 448),
		"Textures/ElvenTracker.png",
		"Textures/apple.png",
		"Textures/HumanMage.png",
		"Textures/WoodenChest.png",
		"Textures/Coin.png",
		new Point(672, 480));

	secondLevel = new GameLevel(
		"Maps/Test.txt",
		new Point(640, 448),
		"Textures/ElvenTracker.png",
		"Textures/apple.png",
		"Textures/HumanMage.png",
		"Textures/WoodenChest.png",
		"Textures/Coin.png",
		new Point(672, 480));

	thirdLevel = new GameLevel(
		"Maps/Exported.txt",
		new Point(640, 448),
		"Textures/ElvenTracker.png",
		"Textures/apple.png",
		"Textures/HumanMage.png",
		"Textures/WoodenChest.png",
		"Textures/Coin.png",
		new Point(672, 480));

	ChangeLevel(basicLevel);
	currentLevelID = 0;
}

void GameLevelManager::Update()
{
	//TeleportToNewMap(TranslatePoint(currentLevel->basicHero->GetDestRect()));
	HeroCollideWithTeleport();
	currentLevel->Update();
}

void GameLevelManager::Render()
{
	currentLevel->Render();
}


Point GameLevelManager::TranslatePoint(SDL_Rect currentPoint)
{
	Point newcurrentPoint;
	newcurrentPoint.x = currentPoint.x;
	newcurrentPoint.y = currentPoint.y;

	return newcurrentPoint;
}


void GameLevelManager::TeleportToNewMap(Point currentPoint)
{
	//currentPoint jest to pozycja bohatera
	if (currentPoint.x == currentLevel->teleportPoint->x && currentPoint.y == currentLevel->teleportPoint->y)
	{
		currentLevelID++;
		std::cout << "Przenieœ siê do innej lokacji" << currentPoint.x << " " << currentPoint.y << std::endl;
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

void GameLevelManager::ChangeLevel(GameLevel *newLevel)
{
	std::cout << "Change level." << std::endl;
	currentLevel = newLevel;
	currentLevel->basicHero->MoveHeroToPoint(
		new Point(
			currentLevel->startingPoint->x,
			currentLevel->startingPoint->y
		)
	);
}

void GameLevelManager::HeroCollideWithTeleport()
{
	for (unsigned int i = 0; i < currentLevel->basicTeleports.size(); i++)
	{
		if (abs(currentLevel->basicHero->GetDestRect().x - currentLevel->basicTeleports[i]->GetDestRect().x) < 30)
		{
			if (abs(currentLevel->basicHero->GetDestRect().y - currentLevel->basicTeleports[i]->GetDestRect().y) < 30)
			{
				std::cout << "Collision with Teleport!" << std::endl;
				SDL_Delay(10);
				currentLevelID++;
				if (currentLevel->basicTeleports[i]->isStartingPoint == true) currentLevelID = currentLevel->basicTeleports[i]->endingDestination;
				else currentLevelID = currentLevel->basicTeleports[i]->startingDestination;
				
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
	}
}