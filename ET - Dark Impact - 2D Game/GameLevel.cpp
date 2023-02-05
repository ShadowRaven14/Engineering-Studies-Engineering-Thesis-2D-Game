#include "GameLevel.h"

GameLevel::GameLevel(const char* bnInfo, SDL_Color* bnColor, std::string bnMap, Point* bnStart, 
	const char* bnHero, const char* bnTel, const char* bnEnemy, const char* bnChest, const char* bnCoin)
{
	std::cout << "THE GAME_LEVEL LOADED." << std::endl;

	//Wyœwietlenie tekstu powitalnego
	welcomeInfo = bnInfo;
	welcomeColor = bnColor;

	//Przygotowanie mapy i bohatera
	basicMap = new BackgroundMap(bnMap);
	startingPoint = bnStart;

	//Dodanie elementów do wektora basicEnemies
	TeleportObject* basicTeleport1 = new TeleportObject("Images/PortalBlue.png", 656, 620, 0);
	TeleportObject* basicTeleport2 = new TeleportObject("Images/PortalRed.png", 262, 310, 1);
	TeleportObject* basicTeleport3 = new TeleportObject("Images/PortalViolet.png", 1050, 310, 2);
	basicTeleports.push_back(basicTeleport1);
	basicTeleports.push_back(basicTeleport2);
	basicTeleports.push_back(basicTeleport3);
	
	//Iloœæ generowanych obiektów
	int n;

	//Dodanie elementów do wektora basicEnemies
	n = rand() % 5 + 1;
	std::cout << n << " enemies spawn." << std::endl;
	for (int i = 0; i < n; i++)
	{
		EnemyObject* basicEnemy = new EnemyObject(bnEnemy);
		basicEnemies.push_back(basicEnemy);
	}

	//Dodanie elementów do wektora basicChests
	n = rand() % 9 + 1;
	std::cout << n << " chests spawn." << std::endl;
	for (int i = 0; i < n; i++)
	{
		ChestObject* basicChest = new ChestObject(bnChest);
		basicChests.push_back(basicChest);
	}

	//Dodanie elementów do wektora basicCoins
	n = rand() % 19 + 1;
	std::cout << n << " coins spawn." << std::endl;
	for (int i = 0; i < n; i++)
	{
		CoinObject* basicCoin = new CoinObject(bnCoin);
		basicCoins.push_back(basicCoin);
	}
}


GameLevel::GameLevel(const GameLevel& tempLevel) //Nie dzia³a?
{
	std::cout << "Konstruktor kopiuj¹cy GameLevel.";

	welcomeInfo = tempLevel.welcomeInfo;
	welcomeColor = tempLevel.welcomeColor;
	startingPoint = tempLevel.startingPoint;
	basicMap = tempLevel.basicMap;

	basicTeleports = tempLevel.basicTeleports;
	basicEnemies = tempLevel.basicEnemies;
	basicChests = tempLevel.basicChests;
	basicCoins = tempLevel.basicCoins;
}

GameLevel& GameLevel::operator= (const GameLevel& tempLevel) //Nie dzia³a?
{
	std::cout << "Przeci¹¿enie operatora '='.";

	welcomeInfo = tempLevel.welcomeInfo;
	welcomeColor = tempLevel.welcomeColor;
	startingPoint = tempLevel.startingPoint;
	basicMap = tempLevel.basicMap;

	basicTeleports = tempLevel.basicTeleports;
	basicEnemies = tempLevel.basicEnemies;
	basicChests = tempLevel.basicChests;
	basicCoins = tempLevel.basicCoins;

	return *this;
}

GameLevel& GameLevel::operator= (GameLevel* tempLevel)
{
	std::cout << "Przeci¹¿enie operatora '='.";

	welcomeInfo = tempLevel->welcomeInfo;
	welcomeColor = tempLevel->welcomeColor;
	startingPoint = tempLevel->startingPoint;
	basicMap = tempLevel->basicMap;

	basicTeleports = tempLevel->basicTeleports;
	basicEnemies = tempLevel->basicEnemies;
	basicChests = tempLevel->basicChests;
	basicCoins = tempLevel->basicCoins;

	return *this;
}

void GameLevel::Update()
{
	for (unsigned int i = 0; i < basicTeleports.size(); i++) basicTeleports[i]->Update();
	for (unsigned int i = 0; i < basicEnemies.size(); i++) basicEnemies[i]->Update();
	for (unsigned int i = 0; i < basicChests.size(); i++) basicChests[i]->Update();
	for (unsigned int i = 0; i < basicCoins.size(); i++) basicCoins[i]->Update();

	//Generowanie tekstu powitalnego
	FontTextureManager::DrawTextTexture(
		FontTextureManager::InitTextDisplay(25, welcomeInfo, *welcomeColor));
}

void GameLevel::Render()
{
	basicMap->DrawMap();
	for (unsigned int i = 0; i < basicTeleports.size(); i++) basicTeleports[i]->Render();
	for (unsigned int i = 0; i < basicEnemies.size(); i++) basicEnemies[i]->Render();
	for (unsigned int i = 0; i < basicChests.size(); i++) basicChests[i]->Render();
	for (unsigned int i = 0; i < basicCoins.size(); i++) basicCoins[i]->Render();

	//Generowanie tekstu powitalnego
	FontTextureManager::DrawTextTexture(
		FontTextureManager::InitTextDisplay(25, welcomeInfo, *welcomeColor));
}