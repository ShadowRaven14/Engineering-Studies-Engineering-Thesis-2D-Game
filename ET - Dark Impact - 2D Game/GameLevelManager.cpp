#include "GameLevelManager.h"
#include "PlayerChoices.h"
#include <string>

PlayerChoices playerChoices;

GameLevelManager::GameLevelManager()
{
	std::cout << "THE GAME_MANAGER ACTIVATED." << std::endl;

	//Postaæ g³ównego bohatera, jest wspólna dla wszystkich poziomów
	mainHero = new HeroObject(0);

	//Poziom Startowy, od niego zaczynamy
	basicGameLevels.push_back(
		new GameLevel(
			0, "Hi! Welcome to start level!",
			new SDL_Color{ 255, 255, 0 },
			"Maps/StartingMap.txt",
			new Point(640, 448)) //new Point(BackgroundMap::mapX / 2, BackgroundMap::mapY / 2))
	);
	
	//Poziom Pierwszy 
	basicGameLevels.push_back(
		new GameLevel(
			1, "Hi! Welcome to 1st level!",
			new SDL_Color{ 255, 0, 255 },
			"Maps/Test.txt",
			new Point(640, 448))
	);

	//Poziom Drugi
	basicGameLevels.push_back(
		new GameLevel(
			2, "Hi! Welcome to 2st level!",
			new SDL_Color{ 0, 255, 255 },
			"Maps/Exported.txt",
			new Point(640, 448))
	);

	//Ustawiamy ID tak aby wskaza³o Poziom na którym jesteœmy
	currentLevelID = 0;

	std::cout << "mainHero->pointInGame: " << mainHero->pointInGame.x << " " << mainHero->pointInGame.y << std::endl;
	std::cout << "middleOFmap: " << BackgroundMap::middleOFmap.x << " " << BackgroundMap::middleOFmap.y << std::endl;

	int tempShiftX = BackgroundMap::middleOFmap.x - mainHero->pointInGame.x;
	BackgroundMap::mapShiftX = BackgroundMap::mapShiftX - tempShiftX;

	int tempShiftY = BackgroundMap::middleOFmap.y - mainHero->pointInGame.y;
	BackgroundMap::mapShiftY = BackgroundMap::mapShiftY - tempShiftY;
}

void GameLevelManager::Update()
{
	basicGameLevels[currentLevelID]->Update();
	mainHero->Update();
	HandleHeroMovement();

	HeroCollideWithTeleport();
	HeroCollideWithChest();
	HeroCollideWithPotion();
	HeroCollideWithCoin();
	if (playerChoices.relationshipWithMages < 5) HeroCollideWithEnemy();

	HandleTextUpdate();
}

void GameLevelManager::Render()
{
	basicGameLevels[currentLevelID]->Render();
	mainHero->Render();

	HandleTextRender();
}

void GameLevelManager::HandleHeroMovement()
{
	int tempShiftX = basicGameLevels[currentLevelID]->startingPoint->x - mainHero->pointInGame.x;
	BackgroundMap::heroInMap.x = BackgroundMap::heroInMap.x - tempShiftX;
	if (BackgroundMap::heroInMap.x - BackgroundMap::middleOFmap.x < distanceToEdge.x
		&& BackgroundMap::heroInMap.x - BackgroundMap::middleOFmap.x > distanceToEdge.x * (-1))
	{
		BackgroundMap::mapShiftX = BackgroundMap::mapShiftX + tempShiftX;
		mainHero->pointInGame.x = basicGameLevels[currentLevelID]->startingPoint->x;
		basicGameLevels[currentLevelID]->MoveAllObjectsBy(tempShiftX, 0);
	}
	else
	{
		BackgroundMap::heroInMap.x = BackgroundMap::heroInMap.x + tempShiftX;
	}

	int tempShiftY = basicGameLevels[currentLevelID]->startingPoint->y - mainHero->pointInGame.y;
	BackgroundMap::heroInMap.y = BackgroundMap::heroInMap.y - tempShiftY;
	if (BackgroundMap::heroInMap.y - BackgroundMap::middleOFmap.y < distanceToEdge.y
		&& BackgroundMap::heroInMap.y - BackgroundMap::middleOFmap.y > distanceToEdge.y * (-1))
	{
		BackgroundMap::mapShiftY = BackgroundMap::mapShiftY + tempShiftY;
		mainHero->pointInGame.y = basicGameLevels[currentLevelID]->startingPoint->y;
		basicGameLevels[currentLevelID]->MoveAllObjectsBy(0, tempShiftY);
	}
	else
	{
		BackgroundMap::heroInMap.y = BackgroundMap::heroInMap.y + tempShiftY;
	}
}

Point GameLevelManager::TranslatePoint(SDL_Rect currentPoint)
{
	Point newcurrentPoint;
	newcurrentPoint.x = currentPoint.x;
	newcurrentPoint.y = currentPoint.y;

	return newcurrentPoint;
}



/*
* ROZPATRZ KOLIZJE
*/

//KOLIZJA Z TELEPORTEM
void GameLevelManager::HeroCollideWithTeleport()
{
	for (unsigned int i = 0; i < basicGameLevels[currentLevelID]->basicTeleports.size(); i++)
	{
		if (abs(mainHero->GetDestRect().x - basicGameLevels[currentLevelID]->basicTeleports[i]->GetDestRect().x) < Game::objectsSize)
		{
			if (abs(mainHero->GetDestRect().y - basicGameLevels[currentLevelID]->basicTeleports[i]->GetDestRect().y) < Game::objectsSize)
			{
				//Sprawadzamy, czy zosta³ nacisniêty przycisk 'f'
				if (mainHero->inputFromKeyboard == 'f')
				{
					std::cout << "Collision with Teleport!" << std::endl;
					SDL_Delay(500);

					//Przenosimy siê na inny Poziom
					currentLevelID = basicGameLevels[currentLevelID]->basicTeleports[i]->destination;
					std::cout << "Change level. Current Level ID = " << currentLevelID << "." << std::endl;
					mainHero->TeleportHeroToPoint(basicGameLevels[currentLevelID]->startingPoint);

					mainHero->inputFromKeyboard = ' ';

					playerChoices.relationMages--;
					playerChoices.setRelationshipWithMages();
				}
			}
		}
	}
}

//KOLIZJA ZE SKRZYNI¥
void GameLevelManager::HeroCollideWithChest()
{
	for (unsigned int i = 0; i < basicGameLevels[currentLevelID]->basicChests.size(); i++)
	{
		if (abs(mainHero->GetDestRect().x - basicGameLevels[currentLevelID]->basicChests[i]->GetDestRect().x) < Game::objectsSize)
		{
			if (abs(mainHero->GetDestRect().y - basicGameLevels[currentLevelID]->basicChests[i]->GetDestRect().y) < Game::objectsSize)
			{
				//Sprawadzamy, czy zosta³ nacisniêty przycisk 'f'
				if (mainHero->inputFromKeyboard == 'f')
				{
					//Upewniamy siê, ¿e skrzynia nie zosta³a ju¿ otwarta
					if (basicGameLevels[currentLevelID]->basicChests[i]->isOpen == false)
					{
						std::cout << "Chest has been collected!" << std::endl;
						SDL_Delay(10);

						//Sprawdzamy czy bohater mo¿e otworzyæ skrzyniê
						if (mainHero->HandleChestCollision(basicGameLevels[currentLevelID]->basicChests[i]->worth) == true)
						{
							basicGameLevels[currentLevelID]->basicChests[i]->currentObjectTexture =
								ImageTextureManager::LoadTexture(basicGameLevels[currentLevelID]->basicChests[i]->usableTextures[1]);
							mainHero->inputFromKeyboard = NULL;
						}
						basicGameLevels[currentLevelID]->basicChests[i]->isOpen = true;
					}
					mainHero->inputFromKeyboard = ' ';
				}
			}
		}
	}
}

//KOLIZJA ZE SKRZYNI¥
void GameLevelManager::HeroCollideWithPotion()
{
	for (unsigned int i = 0; i < basicGameLevels[currentLevelID]->basicPotions.size(); i++)
	{
		if (abs(mainHero->GetDestRect().x - basicGameLevels[currentLevelID]->basicPotions[i]->GetDestRect().x) < Game::objectsSize)
		{
			if (abs(mainHero->GetDestRect().y - basicGameLevels[currentLevelID]->basicPotions[i]->GetDestRect().y) < Game::objectsSize)
			{
				std::cout << "Potion has been collected!" << std::endl;
				SDL_Delay(10);

				//Sprawdzamy czy bohater mo¿e zebraæ miksturê
				if (mainHero->HandlePotionCollision(basicGameLevels[currentLevelID]->basicPotions[i]->power) == true)
				{
					basicGameLevels[currentLevelID]->basicPotions.
						erase(basicGameLevels[currentLevelID]->basicPotions.begin() + i); i--;
				}
			}
		}
	}
}


//KOLIZJA Z MONET¥
void GameLevelManager::HeroCollideWithCoin()
{
	for (unsigned int i = 0; i < basicGameLevels[currentLevelID]->basicCoins.size(); i++)
	{
		if (abs(mainHero->GetDestRect().x - basicGameLevels[currentLevelID]->basicCoins[i]->GetDestRect().x) < Game::objectsSize/2)
		{
			if (abs(mainHero->GetDestRect().y - basicGameLevels[currentLevelID]->basicCoins[i]->GetDestRect().y) < Game::objectsSize/2)
			{
				std::cout << "Coin has been collected!" << std::endl;
				SDL_Delay(10);

				//Sprawdzamy czy bohater mo¿e zebraæ monetê
				if (mainHero->HandleCoinCollision() == true)
				{
					basicGameLevels[currentLevelID]->basicCoins.
						erase(basicGameLevels[currentLevelID]->basicCoins.begin() + i); i--;
				}
			}
		}
	}
}

//KOLIZJA Z WROGIEM
void GameLevelManager::HeroCollideWithEnemy()
{
	for (unsigned int i = 0; i < basicGameLevels[currentLevelID]->basicEnemies.size(); i++)
	{
		if (abs(mainHero->GetDestRect().x - basicGameLevels[currentLevelID]->basicEnemies[i]->GetDestRect().x) < Game::objectsSize)
		{
			if (abs(mainHero->GetDestRect().y - basicGameLevels[currentLevelID]->basicEnemies[i]->GetDestRect().y) < Game::objectsSize)
			{
				std::cout << "Collision with Enemy! ENGAGE!";
				SDL_Delay(10);

				//Sprawdzamy czy nasza postaæ jest wystarczaj¹co silna aby pokonaæ wroga
				if (mainHero->HandleEnemyCollision(basicGameLevels[currentLevelID]->basicEnemies[i]->power) == true)
				{
					basicGameLevels[currentLevelID]->basicEnemies.
						erase(basicGameLevels[currentLevelID]->basicEnemies.begin() + i); i--;

					std::cout << " You have SLAYED enemy!" << std::endl;
				}
				else
				{
					if (playerChoices.relationshipWithMages > 1)
						mainHero->HeroHealthPoints = mainHero->HeroHealthPoints - 1;
					else
						mainHero->HeroHealthPoints = mainHero->HeroHealthPoints - 2;

					std::cout << " HERO HEALTH: " << mainHero->HeroHealthPoints << std::endl;
				}
				
			}
		}
	}
}

void GameLevelManager::HandleTextUpdate()
{
	int numText; std::string strText; int h = 0;

	h = h+25;
	numText = mainHero->HeroHealthPoints;
	strText = std::to_string(numText);
	strText = "HeroHealthPoints: " + strText;
	char const* pcharText_HeroHealthPoints = strText.c_str();
	textHealthPointsObject = new TextObject(pcharText_HeroHealthPoints, new SDL_Color{ 10, 10, 10 }, 0, h);

	h = h+25;
	numText = mainHero->ScorePoints;
	strText = std::to_string(numText);
	strText = "ScorePoints: " + strText;
	char const* pcharText_ScorePoints = strText.c_str();
	textScorePointsObject = new TextObject(pcharText_ScorePoints, new SDL_Color{ 10, 10, 10 }, 0, h);

	h = h+25;
	numText = mainHero->Strength;
	strText = std::to_string(numText);
	strText = "Strength: " + strText;
	char const* pcharText_Strength = strText.c_str();
	textStrengthObject = new TextObject(pcharText_Strength, new SDL_Color{ 10, 10, 10 }, 0, h);

	h = h+25;
	numText = mainHero->Agility;
	strText = std::to_string(numText);
	strText = "Agility: " + strText;
	char const* pcharText_Agility = strText.c_str();
	textAgilityObject = new TextObject(pcharText_Agility, new SDL_Color{ 10, 10, 10 }, 0, h);

	h = h+25;
	numText = mainHero->Intelligence;
	strText = std::to_string(numText);
	strText = "Intelligence: " + strText;
	char const* pcharText_Intelligence = strText.c_str();
	textIntelligenceObject = new TextObject(pcharText_Intelligence, new SDL_Color{ 10, 10, 10 }, 0, h);
}

void GameLevelManager::HandleTextRender()
{
	if (mainHero->inputFromKeyboard == 't')
	{
		textHealthPointsObject->Render();
		textScorePointsObject->Render();
		textStrengthObject->Render();
		textAgilityObject->Render();
		textIntelligenceObject->Render();
		mainHero->inputFromKeyboard = ' ';
	}
	/*SDL_DestroyTexture(textHealthPointsObject->fontTexture);
	SDL_DestroyTexture(textScorePointsObject->fontTexture);
	SDL_DestroyTexture(textStrengthObject->fontTexture);
	SDL_DestroyTexture(textAgilityObject->fontTexture);
	SDL_DestroyTexture(textIntelligenceObject->fontTexture);*/
}
