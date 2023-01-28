#include "GameLevel.h"

GameLevel::GameLevel(const char* bnInfo, SDL_Color* bnColor, std::string bnMap, Point* bnStart, 
	const char* bnHero, const char* bnTel, const char* bnEnemy, const char* bnChest, const char* bnCoin)
{
	std::cout << "THE GAME_LEVEL LOADED." << std::endl;

	//Wy�wietlenie tekstu powitalnego
	welcomeInfo = bnInfo;
	welcomeColor = bnColor;

	//Przygotowanie mapy i bohatera
	basicMap = new BackgroundMap(bnMap);
	startingPoint = bnStart;
	//basicHero = new HeroObject(bnHero, startingPoint);

	//Dodanie element�w do wektora basicEnemies
	TeleportObject* basicTeleport1 = new TeleportObject("Textures/PortalBlue.png", 656, 620, 0);
	TeleportObject* basicTeleport2 = new TeleportObject("Textures/PortalRed.png", 262, 310, 1);
	TeleportObject* basicTeleport3 = new TeleportObject("Textures/PortalViolet.png", 1050, 310, 2);
	basicTeleports.push_back(basicTeleport1);
	basicTeleports.push_back(basicTeleport2);
	basicTeleports.push_back(basicTeleport3);

	//Dodanie element�w do wektora basicEnemies
	for (int i = 0; i < 3; i++)
	{
		EnemyObject* basicEnemy = new EnemyObject(bnEnemy);
		basicEnemies.push_back(basicEnemy);
	}

	//Dodanie element�w do wektora basicChests
	for (int i = 0; i < 5; i++)
	{
		ChestObject* basicChest = new ChestObject(bnChest);
		basicChests.push_back(basicChest);
	}

	//Dodanie element�w do wektora basicCoins
	for (int i = 0; i < 20; i++)
	{
		CoinObject* basicCoin = new CoinObject(bnCoin);
		basicCoins.push_back(basicCoin);
	}
}

GameLevel::GameLevel(const GameLevel& tempLevel) //Nie dzia�a?
{
	std::cout << "Konstruktor kopiuj�cy GameLevel";
	welcomeInfo = tempLevel.welcomeInfo;
	welcomeColor = tempLevel.welcomeColor;
	startingPoint = tempLevel.startingPoint;
	basicMap = tempLevel.basicMap;
	//basicHero = tempLevel.basicHero;
	//basicHero->MoveHeroToPoint(startingPoint);
	for (unsigned int i = 0; i < basicTeleports.size(); i++) basicTeleports[i] = tempLevel.basicTeleports[i];
	for (unsigned int i = 0; i < basicEnemies.size(); i++) basicEnemies[i] = tempLevel.basicEnemies[i];
	for (unsigned int i = 0; i < basicChests.size(); i++) basicChests[i] = tempLevel.basicChests[i];
	for (unsigned int i = 0; i < basicCoins.size(); i++) basicCoins[i] = tempLevel.basicCoins[i];
}

GameLevel& GameLevel::operator= (const GameLevel& tempLevel) //Nie dzia�a?
{
	std::cout << "Konstruktor kopiuj�cy GameLevel";
	welcomeInfo = tempLevel.welcomeInfo;
	welcomeColor = tempLevel.welcomeColor;
	startingPoint = tempLevel.startingPoint;
	basicMap = tempLevel.basicMap;
	//basicHero = tempLevel.basicHero;
	//basicHero->MoveHeroToPoint(startingPoint);
	for (unsigned int i = 0; i < basicTeleports.size(); i++) basicTeleports[i] = tempLevel.basicTeleports[i];
	for (unsigned int i = 0; i < basicEnemies.size(); i++) basicEnemies[i] = tempLevel.basicEnemies[i];
	for (unsigned int i = 0; i < basicChests.size(); i++) basicChests[i] = tempLevel.basicChests[i];
	for (unsigned int i = 0; i < basicCoins.size(); i++) basicCoins[i] = tempLevel.basicCoins[i];

	return *this;
}

GameLevel& GameLevel::operator= (GameLevel* tempLevel)
{
	std::cout << "Konstruktor kopiuj�cy GameLevel";
	welcomeInfo = tempLevel->welcomeInfo;
	welcomeColor = tempLevel->welcomeColor;
	startingPoint = tempLevel->startingPoint;
	basicMap = tempLevel->basicMap;
	//basicHero = tempLevel->basicHero;
	//basicHero->ScorePoints = tempLevel->basicHero->ScorePoints;
	//basicHero->MoveHeroToPoint(startingPoint);
	for (unsigned int i = 0; i < basicTeleports.size(); i++) basicTeleports[i] = tempLevel->basicTeleports[i];
	for (unsigned int i = 0; i < basicEnemies.size(); i++) basicEnemies[i] = tempLevel->basicEnemies[i];
	for (unsigned int i = 0; i < basicChests.size(); i++) basicChests[i] = tempLevel->basicChests[i];
	for (unsigned int i = 0; i < basicCoins.size(); i++) basicCoins[i] = tempLevel->basicCoins[i];

	return *this;
}

void GameLevel::CopyLevel(GameLevel* tempLevel)
{
	std::cout << "Kopiowanie GameLevel. Bez HeroObject." << std::endl;
	welcomeInfo = tempLevel->welcomeInfo;
	welcomeColor = tempLevel->welcomeColor;
	startingPoint = tempLevel->startingPoint;
	basicMap = tempLevel->basicMap;

	for (unsigned int i = 0; i < basicTeleports.size(); i++) basicTeleports[i] = tempLevel->basicTeleports[i];
	for (unsigned int i = 0; i < basicEnemies.size(); i++) basicEnemies[i] = tempLevel->basicEnemies[i];
	for (unsigned int i = 0; i < basicChests.size(); i++) basicChests[i] = tempLevel->basicChests[i];
	for (unsigned int i = 0; i < basicCoins.size(); i++) basicCoins[i] = tempLevel->basicCoins[i];
}

void GameLevel::Update()
{
	for (unsigned int i = 0; i < basicTeleports.size(); i++) basicTeleports[i]->Update();
	for (unsigned int i = 0; i < basicEnemies.size(); i++) basicEnemies[i]->Update();
	for (unsigned int i = 0; i < basicChests.size(); i++) basicChests[i]->Update();
	for (unsigned int i = 0; i < basicCoins.size(); i++) basicCoins[i]->Update();
	//basicHero->Update();

	//HeroCollideWithEnemy();
	//HeroCollideWithChest();
	//HeroCollideWithCoin();

	//Generowanie tekstu powitalnego
	TextTextureManager::DrawTextTexture(
		TextTextureManager::InitTextDisplay(25, welcomeInfo, *welcomeColor));
}

void GameLevel::Render()
{
	basicMap->DrawMap();
	for (unsigned int i = 0; i < basicTeleports.size(); i++) basicTeleports[i]->Render();
	for (unsigned int i = 0; i < basicEnemies.size(); i++) basicEnemies[i]->Render();
	for (unsigned int i = 0; i < basicChests.size(); i++) basicChests[i]->Render();
	for (unsigned int i = 0; i < basicCoins.size(); i++) basicCoins[i]->Render();
	//basicHero->Render();

	//Generowanie tekstu powitalnego
	TextTextureManager::DrawTextTexture(
		TextTextureManager::InitTextDisplay(25, welcomeInfo, *welcomeColor));
}