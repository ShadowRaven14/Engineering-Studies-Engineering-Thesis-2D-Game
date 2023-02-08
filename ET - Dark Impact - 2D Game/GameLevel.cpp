#include "GameLevel.h"

GameLevel::GameLevel()
{
	std::cout << "THE NEW GAME_LEVEL LOADED. IT'S ID = " << "NONE" << "." << std::endl;

	//Identyfikator danego poziomu
	levelID = 100;

	//Wy�wietlenie tekstu powitalnego
	welcomeInfo = nullptr;
	welcomeColor = nullptr;
	welcomeFontTexture = nullptr;

	//Przygotowanie mapy i bohatera
	basicMap = new BackgroundMap("Maps/Test.txt");
	startingPoint = new Point(0, 0);
}

GameLevel::GameLevel(short bnID, const char* bnInfo, SDL_Color* bnColor, std::string bnMap, Point* bnStart)
{
	std::cout << "THE NEW GAME_LEVEL LOADED. IT'S ID = " << bnID << "." << std::endl;

	//Identyfikator danego poziomu
	levelID = bnID;

	//Wy�wietlenie tekstu powitalnego
	welcomeInfo = bnInfo;
	welcomeColor = bnColor;
	welcomeFontTexture = FontTextureManager::InitTextDisplay(25, welcomeInfo, *welcomeColor);

	//Przygotowanie mapy i bohatera
	basicMap = new BackgroundMap(bnMap);
	startingPoint = bnStart;

	//Ilo�� generowanych obiekt�w
	int rand_quantity;
	int rand_type;

	//Tworzymy portal do kolejnego poziomu
	if (levelID < 2) //Je�li nie jeste�my na ostatnim poziomie, tworzymy portal do kolejnego poziomu
		basicTeleports.push_back(new TeleportObject(levelID + 1));
	if (levelID > 0) //Je�li nie jeste�my na poziomie startowym, tworzymy portal do wcze�niejszego poziomu
		basicTeleports.push_back(new TeleportObject(levelID - 1));

	//Dodanie element�w do wektora basicTeleports
	rand_quantity = 0;
	std::cout << rand_quantity << " portals spawn." << std::endl;
	for (int i = 0; i < rand_quantity; i++)
	{
		rand_type = rand() % 3;
		TeleportObject* basicTeleport = new TeleportObject(rand_type);
		basicTeleports.push_back(basicTeleport);
	}

	//Dodanie element�w do wektora basicChests
	rand_quantity = rand() % 8 + 2;
	std::cout << rand_quantity << " chests spawn." << std::endl;
	for (int i = 0; i < rand_quantity; i++)
	{
		rand_type = rand() % 2;
		ChestObject* basicChest = new ChestObject(rand_type);
		basicChests.push_back(basicChest);
	}

	//Dodanie element�w do wektora basicPotions
	rand_quantity = rand() % 8 + 2;
	std::cout << rand_quantity << " potions spawn." << std::endl;
	for (int i = 0; i < rand_quantity; i++)
	{
		rand_type = rand() % 2;
		PotionObject* basicPotion = new PotionObject(rand_type);
		basicPotions.push_back(basicPotion);
	}

	//Dodanie element�w do wektora basicCoins
	rand_quantity = rand() % 10 + 10;
	std::cout << rand_quantity << " coins spawn." << std::endl;
	for (int i = 0; i < rand_quantity; i++)
	{
		rand_type = 0;
		CoinObject* basicCoin = new CoinObject(rand_type);
		basicCoins.push_back(basicCoin);
	}

	//Dodanie element�w do wektora basicEnemies
	rand_quantity = rand() % 5 + 1;
	std::cout << rand_quantity << " enemies spawn." << std::endl;
	for (int i = 0; i < rand_quantity; i++)
	{
		rand_type = rand() % 3;
		EnemyObject* basicEnemy = new EnemyObject(rand_type);
		basicEnemies.push_back(basicEnemy);
	}
}

GameLevel::GameLevel(short bnID, const char* bnInfo, SDL_Color* bnColor, std::string bnMap, Point* bnStart,
	const char* bnHero, const char* bnTel, const char* bnEnemy, const char* bnChest, const char* bnCoin)
{
	std::cout << "THE NEW GAME_LEVEL LOADED. IT'S ID = " << bnID << "." << std::endl;

	//Identyfikator danego poziomu
	levelID = bnID;

	//Wy�wietlenie tekstu powitalnego
	welcomeInfo = bnInfo;
	welcomeColor = bnColor;
	welcomeFontTexture = FontTextureManager::InitTextDisplay(25, welcomeInfo, *welcomeColor);

	//Przygotowanie mapy i bohatera
	basicMap = new BackgroundMap(bnMap);
	startingPoint = bnStart;
	
	//Dodanie element�w do wektora basicEnemies
	TeleportObject* basicTeleport1 = new TeleportObject("Images/PortalBlue.png", 656, 620, 0);
	TeleportObject* basicTeleport2 = new TeleportObject("Images/PortalRed.png", 262, 310, 1);
	TeleportObject* basicTeleport3 = new TeleportObject("Images/PortalViolet.png", 1050, 310, 2);
	basicTeleports.push_back(basicTeleport1);
	basicTeleports.push_back(basicTeleport2);
	basicTeleports.push_back(basicTeleport3);

	//Ilo�� generowanych obiekt�w
	int rand_quantity;

	//Dodanie element�w do wektora basicChests
	rand_quantity = rand() % 8 + 2;
	std::cout << rand_quantity << " chests spawn." << std::endl;
	for (int i = 0; i < rand_quantity; i++)
	{
		ChestObject* basicChest = new ChestObject(bnChest);
		basicChests.push_back(basicChest);
	}

	//Dodanie element�w do wektora basicCoins
	rand_quantity = rand() % 10 + 10;
	std::cout << rand_quantity << " coins spawn." << std::endl;
	for (int i = 0; i < rand_quantity; i++)
	{
		CoinObject* basicCoin = new CoinObject(bnCoin);
		basicCoins.push_back(basicCoin);
	}

	//Dodanie element�w do wektora basicEnemies
	rand_quantity = rand() % 5 + 1;
	std::cout << rand_quantity << " enemies spawn." << std::endl;
	for (int i = 0; i < rand_quantity; i++)
	{
		//EnemyObject* basicEnemy = new EnemyObject(bnEnemy);
		EnemyObject* basicEnemy = new EnemyObject(1);
		basicEnemies.push_back(basicEnemy);
	}

	
}

GameLevel::GameLevel(const GameLevel& tempLevel) //Nie dzia�a?
{
	std::cout << "Konstruktor kopiuj�cy GameLevel.";

	levelID = tempLevel.levelID;

	welcomeInfo = tempLevel.welcomeInfo;
	welcomeColor = tempLevel.welcomeColor;
	startingPoint = tempLevel.startingPoint;
	basicMap = tempLevel.basicMap;

	basicTeleports = tempLevel.basicTeleports;
	basicChests = tempLevel.basicChests;
	basicPotions = tempLevel.basicPotions;
	basicCoins = tempLevel.basicCoins;
	basicEnemies = tempLevel.basicEnemies;
}

GameLevel& GameLevel::operator= (const GameLevel& tempLevel) //Nie dzia�a?
{
	std::cout << "Przeci��enie operatora '='.";

	levelID = tempLevel.levelID;

	welcomeInfo = tempLevel.welcomeInfo;
	welcomeColor = tempLevel.welcomeColor;
	startingPoint = tempLevel.startingPoint;
	basicMap = tempLevel.basicMap;

	basicTeleports = tempLevel.basicTeleports;
	basicChests = tempLevel.basicChests;
	basicPotions = tempLevel.basicPotions;
	basicCoins = tempLevel.basicCoins;
	basicEnemies = tempLevel.basicEnemies;

	return *this;
}

GameLevel& GameLevel::operator= (GameLevel* tempLevel)
{
	std::cout << "Przeci��enie operatora '='.";

	levelID = tempLevel->levelID;

	welcomeInfo = tempLevel->welcomeInfo;
	welcomeColor = tempLevel->welcomeColor;
	startingPoint = tempLevel->startingPoint;
	basicMap = tempLevel->basicMap;

	basicTeleports = tempLevel->basicTeleports;
	basicChests = tempLevel->basicChests;
	basicPotions = tempLevel->basicPotions;
	basicCoins = tempLevel->basicCoins;
	basicEnemies = tempLevel->basicEnemies;

	return *this;
}

void GameLevel::Update()
{
	basicMap->Update();
	for (unsigned int i = 0; i < basicTeleports.size(); i++) basicTeleports[i]->Update();
	for (unsigned int i = 0; i < basicChests.size(); i++) basicChests[i]->Update();
	for (unsigned int i = 0; i < basicPotions.size(); i++) basicPotions[i]->Update();
	for (unsigned int i = 0; i < basicCoins.size(); i++) basicCoins[i]->Update();
	for (unsigned int i = 0; i < basicEnemies.size(); i++) basicEnemies[i]->Update();
}

void GameLevel::Render()
{
	basicMap->Render();
	for (unsigned int i = 0; i < basicTeleports.size(); i++) basicTeleports[i]->Render();
	for (unsigned int i = 0; i < basicChests.size(); i++) basicChests[i]->Render();
	for (unsigned int i = 0; i < basicPotions.size(); i++) basicPotions[i]->Render();
	for (unsigned int i = 0; i < basicCoins.size(); i++) basicCoins[i]->Render();
	for (unsigned int i = 0; i < basicEnemies.size(); i++) basicEnemies[i]->Render();

	//Generowanie tekstu powitalnego
	FontTextureManager::DrawTextTexture(welcomeFontTexture);
}