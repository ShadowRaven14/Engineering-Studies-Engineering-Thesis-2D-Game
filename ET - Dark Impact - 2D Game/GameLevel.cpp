#include "GameLevel.h"

//Konstruktor
GameLevel::GameLevel()
{
	std::cout << "THE NEW GAME_LEVEL LOADED. IT'S ID = " << "NONE" << "." << std::endl;

	//Identyfikator danego poziomu
	levelID = 100;

	//Wyœwietlenie tekstu powitalnego
	info = nullptr;
	color = nullptr;
	fontTexture = nullptr;

	//Przygotowanie mapy i bohatera
	basicMap = new BackgroundMap("Maps/Test.txt");
	startingPoint = new Point(0, 0);

	std::cout << std::endl;
}

//Konstruktor
GameLevel::GameLevel(short bnID, const char* bnInfo, SDL_Color* bnColor, std::string bnMap, Point* bnStart)
{
	std::cout << "=> " << "THE NEW GAME_LEVEL LOADED. IT'S ID = " << bnID << "." << std::endl;

	//Identyfikator danego poziomu
	levelID = bnID;

	//Wyœwietlenie tekstu powitalnego
	info = bnInfo;
	color = bnColor;
	fontTexture = FontTextureManager::InitTextDisplay(25, info, *color);

	//Przygotowanie mapy i bohatera
	basicMap = new BackgroundMap(bnMap);
	startingPoint = bnStart;

	//Iloœæ generowanych obiektów
	int rand_quantity;
	int rand_type;

	//Tworzymy portal do kolejnego poziomu
	if (levelID < 2) //Jeœli nie jesteœmy na ostatnim poziomie, tworzymy portal do kolejnego poziomu
		basicTeleports.push_back(new TeleportObject(levelID + 1));
	if (levelID > 0) //Jeœli nie jesteœmy na poziomie startowym, tworzymy portal do wczeœniejszego poziomu
		basicTeleports.push_back(new TeleportObject(levelID - 1));

	//Dodanie elementów do wektora basicChests
	rand_quantity = rand() % 8 + 2;
	std::cout << "==> " << rand_quantity << " chests spawn." << std::endl;
	for (int i = 0; i < rand_quantity; i++)
	{
		rand_type = rand() % 3;
		ChestObject* basicChest = new ChestObject(rand_type);
		basicChests.push_back(basicChest);
	}

	//Dodanie elementów do wektora basicItemApples
	rand_quantity = rand() % 2 + 2;
	std::cout << "==> " << rand_quantity << " apples item spawn." << std::endl;
	for (int i = 0; i < rand_quantity; i++)
	{
		rand_type = rand() % 3;
		AppleItemObject* basicApple = new AppleItemObject(rand_type);
		basicItemApples.push_back(basicApple);
	}

	//Dodanie elementów do wektora basicItemCoins
	rand_quantity = rand() % 20 + 20;
	std::cout << "==> " << rand_quantity << " coins item spawn." << std::endl;
	for (int i = 0; i < rand_quantity; i++)
	{
		rand_type = 0;
		CoinObject* basicCoin = new CoinObject(rand_type);
		basicItemCoins.push_back(basicCoin);
	}

	//Dodanie elementów do wektora basicItemPotions
	rand_quantity = rand() % 8 + 2;
	std::cout << "==> " << rand_quantity << " potions item spawn." << std::endl;
	for (int i = 0; i < rand_quantity; i++)
	{
		rand_type = rand() % 3;
		PotionObject* basicPotion = new PotionObject(rand_type);
		basicItemPotions.push_back(basicPotion);
	}

	//Dodanie elementów do wektora basicMageEnemies
	rand_quantity = rand() % 2 + 2;
	std::cout << "==> " << rand_quantity << " mage enemies spawn." << std::endl;
	for (int i = 0; i < rand_quantity; i++)
	{
		rand_type = rand() % 3;
		EnemyMageObject* basicEnemy = new EnemyMageObject(rand_type);
		basicMageEnemies.push_back(basicEnemy);
	}

	//Dodanie elementów do wektora basicSentinelEnemies
	rand_quantity = rand() % 2 + 1;
	std::cout << "==> " << rand_quantity << " sentinel enemies spawn." << std::endl;
	for (int i = 0; i < rand_quantity; i++)
	{
		rand_type = rand() % 2;
		EnemySentinelObject* basicEnemy = new EnemySentinelObject(rand_type);
		basicSentinelEnemies.push_back(basicEnemy);
	}

	std::cout << std::endl;
}

//Konstruktor
GameLevel::GameLevel(short bnID, const char* bnInfo, SDL_Color* bnColor, std::string bnMap, Point* bnStart,
	const char* bnHero, const char* bnTel, const char* bnEnemy, const char* bnChest, const char* bnCoin)
{
	std::cout << "=> " << "THE NEW GAME_LEVEL LOADED. IT'S ID = " << bnID << "." << std::endl;

	//Identyfikator danego poziomu
	levelID = bnID;

	//Wyœwietlenie tekstu powitalnego
	info = bnInfo;
	color = bnColor;
	fontTexture = FontTextureManager::InitTextDisplay(25, info, *color);

	//Przygotowanie mapy i bohatera
	basicMap = new BackgroundMap(bnMap);
	startingPoint = bnStart;
	
	//Dodanie elementów do wektora basicTeleports
	TeleportObject* basicTeleport1 = new TeleportObject("Images/PortalBlue.png", 656, 620, 0);
	TeleportObject* basicTeleport2 = new TeleportObject("Images/PortalRed.png", 262, 310, 1);
	TeleportObject* basicTeleport3 = new TeleportObject("Images/PortalViolet.png", 1050, 310, 2);
	basicTeleports.push_back(basicTeleport1);
	basicTeleports.push_back(basicTeleport2);
	basicTeleports.push_back(basicTeleport3);

	//Iloœæ generowanych obiektów
	int rand_quantity;

	//Dodanie elementów do wektora basicChests
	rand_quantity = rand() % 8 + 2;
	std::cout << "==> " << rand_quantity << " chests spawn." << std::endl;
	for (int i = 0; i < rand_quantity; i++)
	{
		ChestObject* basicChest = new ChestObject(bnChest);
		basicChests.push_back(basicChest);
	}

	//Dodanie elementów do wektora basicItemCoins
	rand_quantity = rand() % 10 + 10;
	std::cout << "==> " << rand_quantity << " coins spawn." << std::endl;
	for (int i = 0; i < rand_quantity; i++)
	{
		CoinObject* basicCoin = new CoinObject(bnCoin);
		basicItemCoins.push_back(basicCoin);
	}

	std::cout << std::endl;
}

//Konstruktor
GameLevel::GameLevel(const GameLevel& tempLevel)
{
	std::cout << "Konstruktor kopiuj¹cy GameLevel.";

	levelID = tempLevel.levelID;

	info = tempLevel.info;
	color = tempLevel.color;
	startingPoint = tempLevel.startingPoint;
	basicMap = tempLevel.basicMap;

	basicTeleports = tempLevel.basicTeleports;
	basicChests = tempLevel.basicChests;

	basicItemApples = tempLevel.basicItemApples;
	basicItemCoins = tempLevel.basicItemCoins;
	basicItemPotions = tempLevel.basicItemPotions;

	basicMageEnemies = tempLevel.basicMageEnemies;
	basicSentinelEnemies = tempLevel.basicSentinelEnemies;
}

//Przeci¹¿enie operatora
GameLevel& GameLevel::operator= (const GameLevel& tempLevel)
{
	std::cout << "Przeci¹¿enie operatora '='.";

	levelID = tempLevel.levelID;

	info = tempLevel.info;
	color = tempLevel.color;
	startingPoint = tempLevel.startingPoint;
	basicMap = tempLevel.basicMap;

	basicTeleports = tempLevel.basicTeleports;
	basicChests = tempLevel.basicChests;

	basicItemApples = tempLevel.basicItemApples;
	basicItemCoins = tempLevel.basicItemCoins;
	basicItemPotions = tempLevel.basicItemPotions;

	basicMageEnemies = tempLevel.basicMageEnemies;
	basicSentinelEnemies = tempLevel.basicSentinelEnemies;

	return *this;
}

//Przeci¹¿enie operatora
GameLevel& GameLevel::operator= (GameLevel* tempLevel)
{
	std::cout << "Przeci¹¿enie operatora '='.";

	levelID = tempLevel->levelID;

	info = tempLevel->info;
	color = tempLevel->color;
	startingPoint = tempLevel->startingPoint;
	basicMap = tempLevel->basicMap;

	basicTeleports = tempLevel->basicTeleports;
	basicChests = tempLevel->basicChests;

	basicItemApples = tempLevel->basicItemApples;
	basicItemCoins = tempLevel->basicItemCoins;
	basicItemPotions = tempLevel->basicItemPotions;

	basicMageEnemies = tempLevel->basicMageEnemies;
	basicSentinelEnemies = tempLevel->basicSentinelEnemies;

	return *this;
}

//Aktualizacja
void GameLevel::Update()
{
	basicMap->Update();
	for (unsigned int i = 0; i < basicTeleports.size(); i++) basicTeleports[i]->Update();
	for (unsigned int i = 0; i < basicChests.size(); i++) basicChests[i]->Update();

	for (unsigned int i = 0; i < basicItemApples.size(); i++) basicItemApples[i]->Update();
	for (unsigned int i = 0; i < basicItemCoins.size(); i++) basicItemCoins[i]->Update();
	for (unsigned int i = 0; i < basicItemPotions.size(); i++) basicItemPotions[i]->Update();

	for (unsigned int i = 0; i < basicMageEnemies.size(); i++) basicMageEnemies[i]->Update();
	for (unsigned int i = 0; i < basicSentinelEnemies.size(); i++) basicSentinelEnemies[i]->Update();
}

//Renderowanie
void GameLevel::Render()
{
	basicMap->Render();
	for (unsigned int i = 0; i < basicTeleports.size(); i++) basicTeleports[i]->Render();
	for (unsigned int i = 0; i < basicChests.size(); i++) basicChests[i]->Render();

	for (unsigned int i = 0; i < basicItemApples.size(); i++) basicItemApples[i]->Render();
	for (unsigned int i = 0; i < basicItemCoins.size(); i++) basicItemCoins[i]->Render();
	for (unsigned int i = 0; i < basicItemPotions.size(); i++) basicItemPotions[i]->Render();

	for (unsigned int i = 0; i < basicMageEnemies.size(); i++) basicMageEnemies[i]->Render();
	for (unsigned int i = 0; i < basicSentinelEnemies.size(); i++) basicSentinelEnemies[i]->Render();

	//Generowanie tekstu powitalnego
	FontTextureManager::DrawTextTexture(fontTexture);
}

//Poruszenie wszystkich GameObjects
void GameLevel::MoveAllObjectsBy(int x, int y)
{
	for (unsigned int i = 0; i < basicTeleports.size(); i++) basicTeleports[i]->MoveObjectBy(x,y);
	for (unsigned int i = 0; i < basicChests.size(); i++) basicChests[i]->MoveObjectBy(x, y);

	for (unsigned int i = 0; i < basicItemApples.size(); i++) basicItemApples[i]->MoveObjectBy(x, y);
	for (unsigned int i = 0; i < basicItemCoins.size(); i++) basicItemCoins[i]->MoveObjectBy(x, y);
	for (unsigned int i = 0; i < basicItemPotions.size(); i++) basicItemPotions[i]->MoveObjectBy(x, y);

	for (unsigned int i = 0; i < basicMageEnemies.size(); i++) basicMageEnemies[i]->MoveObjectBy(x, y);
	for (unsigned int i = 0; i < basicSentinelEnemies.size(); i++) basicSentinelEnemies[i]->MoveObjectBy(x, y);
}
