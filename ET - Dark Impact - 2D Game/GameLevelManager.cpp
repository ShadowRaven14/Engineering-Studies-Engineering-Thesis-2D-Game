#include "GameLevelManager.h"
#include "HeroChoices.h"
#include <string>

HeroChoices heroChoices;

GameLevelManager::GameLevelManager()
{
	std::cout << "THE GAME_MANAGER ACTIVATED." << std::endl << std::endl;

	//Postaæ g³ównego bohatera, jest wspólna dla wszystkich poziomów
	mainHero = new MainHeroObject(0);

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

	HeroCollide_With_Teleport();
	HeroCollide_With_Chest();

	HeroCollide_With_AppleItem();
	HeroCollide_With_CoinItem();
	HeroCollide_With_PotionItem();
	
	if (heroChoices.relationshipWithMages < 5) HeroCollide_With_MageEnemy();
	if (heroChoices.relationshipWithSentinels < 5) HeroCollide_With_SentinelEnemy();

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

void GameLevelManager::ChangeHeroTexture_DamageOrHeal(bool damage)
{
	const char* tempHeroTexture = (const char*)mainHero->currentObjectTexture;

	if (damage == true)
	{
		if (tempHeroTexture == mainHero->usableTextures[0])
		{
			mainHero->currentObjectTexture = ImageTextureManager::LoadTexture(mainHero->usableTextures[2]);
		}
		if (tempHeroTexture == mainHero->usableTextures[1])
		{
			mainHero->currentObjectTexture = ImageTextureManager::LoadTexture(mainHero->usableTextures[3]);
		}
	}
	else
	{
		if (tempHeroTexture == mainHero->usableTextures[0])
		{
			mainHero->currentObjectTexture = ImageTextureManager::LoadTexture(mainHero->usableTextures[4]);
		}
		if (tempHeroTexture == mainHero->usableTextures[1])
		{
			mainHero->currentObjectTexture = ImageTextureManager::LoadTexture(mainHero->usableTextures[5]);
		}
	}
}



/*
* ROZPATRZ KOLIZJE
*/

//KOLIZJA Z TELEPORTEM
void GameLevelManager::HeroCollide_With_Teleport()
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
					if (mainHero->HandleTeleportCollision(basicGameLevels[currentLevelID]->basicTeleports[i]->challenge) == true)
					{
						std::cout << "Collision with Teleport!" << std::endl;
						SDL_Delay(500);

						//Przenosimy siê na inny Poziom
						currentLevelID = basicGameLevels[currentLevelID]->basicTeleports[i]->destination;
						std::cout << "Change level. Current Level ID = " << currentLevelID << "." << std::endl;
						mainHero->TeleportHeroToPoint(basicGameLevels[currentLevelID]->startingPoint);

						mainHero->inputFromKeyboard = ' ';

						if (heroChoices.relationshipWithSentinels > 1)
						{
							heroChoices.relationSentinels--;
							heroChoices.setRelationshipWithSentinels();
						}
					}
				}
			}
		}
	}
}

//KOLIZJA ZE SKRZYNI¥
void GameLevelManager::HeroCollide_With_Chest()
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
						//Sprawdzamy czy bohater mo¿e otworzyæ skrzyniê
						if (mainHero->HandleChestCollision(basicGameLevels[currentLevelID]->basicChests[i]->challenge) == true)
						{
							std::cout << "Chest has been collected!" << std::endl;

							basicGameLevels[currentLevelID]->basicChests[i]->currentObjectTexture =
								ImageTextureManager::LoadTexture(basicGameLevels[currentLevelID]->basicChests[i]->usableTextures[1]);
							mainHero->inputFromKeyboard = NULL;

							if (heroChoices.relationshipWithMages > 1)
							{
								heroChoices.relationMages--;
								heroChoices.setRelationshipWithMages();
							}

							basicGameLevels[currentLevelID]->basicChests[i]->isOpen = true;					
						}
					}
					mainHero->inputFromKeyboard = ' ';
				}
			}
		}
	}
}


//KOLIZJA Z PRZEDMIOTEM JAB£KIEM
void GameLevelManager::HeroCollide_With_AppleItem()
{
	for (unsigned int i = 0; i < basicGameLevels[currentLevelID]->basicItemApples.size(); i++)
	{
		if (abs(mainHero->GetDestRect().x - basicGameLevels[currentLevelID]->basicItemApples[i]->GetDestRect().x) < Game::objectsSize / 2)
		{
			if (abs(mainHero->GetDestRect().y - basicGameLevels[currentLevelID]->basicItemApples[i]->GetDestRect().y) < Game::objectsSize / 2)
			{
				std::cout << "Apple has been collected!" << std::endl;

				//Sprawdzamy czy bohater mo¿e zebraæ jab³ko
				if (mainHero->HandleAppleCollision(basicGameLevels[currentLevelID]->basicItemApples[i]->power) == true)
				{
					mainHero->ChangeHeroTexture_DamageOrHeal(false);
					std::cout << " HERO HEALTH: " << mainHero->HeroHealthPoints << std::endl;

					basicGameLevels[currentLevelID]->basicItemApples.
						erase(basicGameLevels[currentLevelID]->basicItemApples.begin() + i); i--;

					if (heroChoices.relationshipWithMages < 5)
					{
						heroChoices.relationMages++;
						heroChoices.setRelationshipWithMages();
					}
					
					if (heroChoices.relationshipWithSentinels < 5)
					{
						heroChoices.relationSentinels++;
						heroChoices.setRelationshipWithSentinels();
					}
				}
			}
		}
	}
}


//KOLIZJA Z PRZEDMIOTEM MONET¥
void GameLevelManager::HeroCollide_With_CoinItem()
{
	for (unsigned int i = 0; i < basicGameLevels[currentLevelID]->basicItemCoins.size(); i++)
	{
		if (abs(mainHero->GetDestRect().x - basicGameLevels[currentLevelID]->basicItemCoins[i]->GetDestRect().x) < Game::objectsSize / 2)
		{
			if (abs(mainHero->GetDestRect().y - basicGameLevels[currentLevelID]->basicItemCoins[i]->GetDestRect().y) < Game::objectsSize / 2)
			{
				std::cout << "Coin has been collected!" << std::endl;

				//Sprawdzamy czy bohater mo¿e zebraæ monetê
				if (mainHero->HandleCoinCollision(10) == true)
				{
					basicGameLevels[currentLevelID]->basicItemCoins.
						erase(basicGameLevels[currentLevelID]->basicItemCoins.begin() + i); i--;
				}
			}
		}
	}
}


//KOLIZJA Z PRZEDMIOTEM MIKSTUR¥
void GameLevelManager::HeroCollide_With_PotionItem()
{
	for (unsigned int i = 0; i < basicGameLevels[currentLevelID]->basicItemPotions.size(); i++)
	{
		if (abs(mainHero->GetDestRect().x - basicGameLevels[currentLevelID]->basicItemPotions[i]->GetDestRect().x) < Game::objectsSize / 2)
		{
			if (abs(mainHero->GetDestRect().y - basicGameLevels[currentLevelID]->basicItemPotions[i]->GetDestRect().y) < Game::objectsSize / 2)
			{
				std::cout << "Potion has been collected!" << std::endl;
				
				//Sprawdzamy czy bohater mo¿e zebraæ miksturê
				if (mainHero->HandlePotionCollision(basicGameLevels[currentLevelID]->basicItemPotions[i]->power) == true)
				{
					mainHero->ChangeHeroTexture_DamageOrHeal(false);
					std::cout << " HERO HEALTH: " << mainHero->HeroHealthPoints << std::endl;

					basicGameLevels[currentLevelID]->basicItemPotions.
						erase(basicGameLevels[currentLevelID]->basicItemPotions.begin() + i); i--;

					if (heroChoices.relationshipWithMages > 1)
					{
						heroChoices.relationMages--;
						heroChoices.setRelationshipWithMages();
					}
				}
			}
		}
	}
}


//KOLIZJA Z WROGIEM MAGIEM
void GameLevelManager::HeroCollide_With_MageEnemy()
{
	for (unsigned int i = 0; i < basicGameLevels[currentLevelID]->basicMageEnemies.size(); i++)
	{
		if (abs(mainHero->GetDestRect().x - basicGameLevels[currentLevelID]->basicMageEnemies[i]->GetDestRect().x) < Game::objectsSize)
		{
			if (abs(mainHero->GetDestRect().y - basicGameLevels[currentLevelID]->basicMageEnemies[i]->GetDestRect().y) < Game::objectsSize)
			{
				std::cout << "Collision with Enemy Mage! ENGAGE!";

				//Sprawdzamy czy nasza postaæ jest wystarczaj¹co silna aby pokonaæ wroga
				if (mainHero->HandleEnemyCollision(basicGameLevels[currentLevelID]->basicMageEnemies[i]->power) == true)
				{
					basicGameLevels[currentLevelID]->basicMageEnemies.
						erase(basicGameLevels[currentLevelID]->basicMageEnemies.begin() + i); i--;

					std::cout << " You have SLAYED enemy!" << std::endl;
				}
				else
				{
					mainHero->ChangeHeroTexture_DamageOrHeal(true);

					if (heroChoices.relationshipWithMages > 1)
						mainHero->HeroHealthPoints = mainHero->HeroHealthPoints - 1;
					else
						mainHero->HeroHealthPoints = mainHero->HeroHealthPoints - 2;

					//std::cout << " HERO HEALTH: " << mainHero->HeroHealthPoints << std::endl;
				}
			}
		}
	}
}


//KOLIZJA Z WROGIEM STRA¯NIKIEM
void GameLevelManager::HeroCollide_With_SentinelEnemy()
{
	for (unsigned int i = 0; i < basicGameLevels[currentLevelID]->basicSentinelEnemies.size(); i++)
	{
		if (abs(mainHero->GetDestRect().x - basicGameLevels[currentLevelID]->basicSentinelEnemies[i]->GetDestRect().x) < Game::objectsSize)
		{
			if (abs(mainHero->GetDestRect().y - basicGameLevels[currentLevelID]->basicSentinelEnemies[i]->GetDestRect().y) < Game::objectsSize)
			{
				std::cout << "Collision with Enemy Sentinel! ENGAGE!";

				//Sprawdzamy czy nasza postaæ jest wystarczaj¹co silna aby pokonaæ wroga
				if (mainHero->HandleEnemyCollision(basicGameLevels[currentLevelID]->basicSentinelEnemies[i]->power) == true)
				{
					basicGameLevels[currentLevelID]->basicSentinelEnemies.
						erase(basicGameLevels[currentLevelID]->basicSentinelEnemies.begin() + i); i--;

					std::cout << " You have SLAYED enemy!" << std::endl;
				}
				else
				{
					mainHero->ChangeHeroTexture_DamageOrHeal(true);

					if (heroChoices.relationshipWithSentinels > 1)
						mainHero->HeroHealthPoints = mainHero->HeroHealthPoints - 1;
					else
						mainHero->HeroHealthPoints = mainHero->HeroHealthPoints - 2;

					//std::cout << " HERO HEALTH: " << mainHero->HeroHealthPoints << std::endl;
				}
			}
		}
	}
}


void GameLevelManager::HandleTextUpdate()
{
	int numText; std::string strText; int h = 0;

	h = h + 35;
	numText = mainHero->HeroHealthPoints;
	strText = std::to_string(numText);
	strText = " HeroHealthPoints: " + strText;
	char const* pcharText_HeroHealthPoints = strText.c_str();
	textHealthPointsObject = new TextObject(pcharText_HeroHealthPoints, new SDL_Color{ 10, 10, 10 }, 0, h);

	h = h + 25;
	numText = mainHero->ScorePoints;
	strText = std::to_string(numText);
	strText = " ScorePoints: " + strText;
	char const* pcharText_ScorePoints = strText.c_str();
	textScorePointsObject = new TextObject(pcharText_ScorePoints, new SDL_Color{ 10, 10, 10 }, 0, h);


	h = h + 35;
	numText = mainHero->Strength;
	strText = std::to_string(numText);
	strText = " Strength: " + strText;
	char const* pcharText_Strength = strText.c_str();
	textStrengthObject = new TextObject(pcharText_Strength, new SDL_Color{ 10, 10, 10 }, 0, h);

	h = h + 25;
	numText = mainHero->Agility;
	strText = std::to_string(numText);
	strText = " Agility: " + strText;
	char const* pcharText_Agility = strText.c_str();
	textAgilityObject = new TextObject(pcharText_Agility, new SDL_Color{ 10, 10, 10 }, 0, h);

	h = h + 25;
	numText = mainHero->Intelligence;
	strText = std::to_string(numText);
	strText = " Intelligence: " + strText;
	char const* pcharText_Intelligence = strText.c_str();
	textIntelligenceObject = new TextObject(pcharText_Intelligence, new SDL_Color{ 10, 10, 10 }, 0, h);


	h = h + 35;
	numText = heroChoices.relationMages;
	strText = std::to_string(numText);
	strText = " MageRelations: " + strText;
	char const* pcharText_MageRelations = strText.c_str();
	textMageRelationsObject = new TextObject(pcharText_MageRelations, new SDL_Color{ 10, 10, 10 }, 0, h);

	h = h + 25;
	numText = heroChoices.relationSentinels;
	strText = std::to_string(numText);
	strText = " SentinelsRelations: " + strText;
	char const* pcharText_SentinelsRelations = strText.c_str();	
	textSentinelsRelationsObject = new TextObject(pcharText_SentinelsRelations, new SDL_Color{ 10, 10, 10 }, 0, h);
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

		textMageRelationsObject->Render();
		textSentinelsRelationsObject->Render();	

		mainHero->inputFromKeyboard = ' ';
	}

	/*SDL_DestroyTexture(textHealthPointsObject->fontTexture);
	SDL_DestroyTexture(textScorePointsObject->fontTexture);
	SDL_DestroyTexture(textStrengthObject->fontTexture);
	SDL_DestroyTexture(textAgilityObject->fontTexture);
	SDL_DestroyTexture(textIntelligenceObject->fontTexture);*/
}
