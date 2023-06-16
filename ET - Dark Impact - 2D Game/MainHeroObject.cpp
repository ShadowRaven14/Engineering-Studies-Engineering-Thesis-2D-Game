#include "MainHeroObject.h"

MainHeroObject::MainHeroObject(unsigned short type)
{
	const char* tempTex;

	switch (type)
	{
	case 0:
		tempTex = "Images/ElvenTracker_GoRight.png";
		usableTextures.push_back(tempTex);
		tempTex = "Images/ElvenTracker_GoLeft.png";
		usableTextures.push_back(tempTex);

		tempTex = "Images/ElvenTracker_GoRight_damaged.png";
		usableTextures.push_back(tempTex);
		tempTex = "Images/ElvenTracker_GoLeft_damaged.png";
		usableTextures.push_back(tempTex);

		tempTex = "Images/ElvenTracker_GoRight_healed.png";
		usableTextures.push_back(tempTex);
		tempTex = "Images/ElvenTracker_GoLeft_healed.png";
		usableTextures.push_back(tempTex);

		break;

	default:
		std::cout << "Error: Type Construktor." << std::endl;
		tempTex = "Images/AppleNormal.png";
		usableTextures.push_back(tempTex);
		break;
	}

	BasicInit(usableTextures[0],
		(Game::windowX - (srcRect.w / 2)) / 2,
		(Game::windowY - (srcRect.h / 2)) / 2);
}

//PODSTAWOWE
//Konstruktor bohatera
MainHeroObject::MainHeroObject(const char* texturesheet, int x, int y)
{
	BasicInit(texturesheet, x, y); //Podstawowa funkcja z klasy interfejsu
}

//Konstruktor bohatera
MainHeroObject::MainHeroObject(const char* texturesheet, Point* point)
{
	BasicInit(texturesheet, point->x, point->y); //Podstawowa funkcja z klasy interfejsu
}

MainHeroObject::MainHeroObject(const MainHeroObject& tempHero)
{
	std::cout << "Konstruktor kopiuj¹cy MainHeroObject";
	currentObjectTexture = tempHero.currentObjectTexture;

	HeroName = tempHero.HeroName;
	HeroHealthPoints = tempHero.HeroHealthPoints;
	Strength = tempHero.Strength, Intelligence = tempHero.Intelligence, Agility = tempHero.Agility;

	ScorePoints = tempHero.ScorePoints;
	CollectedChests = tempHero.CollectedChests;
	CollectedCoins = tempHero.CollectedCoins;
	SlayedEnemies = tempHero.SlayedEnemies;

	//cordsOfHero = tempHero.cordsOfHero;
	pointInGame.x = tempHero.pointInGame.x;
	pointInGame.y = tempHero.pointInGame.y;
	inputFromKeyboard = tempHero.inputFromKeyboard;
	textureNumber = tempHero.textureNumber;
	speedShift = tempHero.speedShift;
}

MainHeroObject& MainHeroObject::operator= (const MainHeroObject& tempHero)
{
	std::cout << "Konstruktor kopiuj¹cy MainHeroObject";
	currentObjectTexture = tempHero.currentObjectTexture;

	HeroName = tempHero.HeroName;
	HeroHealthPoints = tempHero.HeroHealthPoints;
	Strength = tempHero.Strength, Intelligence = tempHero.Intelligence, Agility = tempHero.Agility;

	ScorePoints = tempHero.ScorePoints;
	CollectedChests = tempHero.CollectedChests;
	CollectedCoins = tempHero.CollectedCoins;
	SlayedEnemies = tempHero.SlayedEnemies;

	//cordsOfHero = tempHero.cordsOfHero;
	pointInGame.x = tempHero.pointInGame.x;
	pointInGame.y = tempHero.pointInGame.y;
	inputFromKeyboard = tempHero.inputFromKeyboard;
	textureNumber = tempHero.textureNumber;
	speedShift = tempHero.speedShift;

	return *this;
}

MainHeroObject& MainHeroObject::operator= (MainHeroObject* tempHero)
{
	std::cout << "Konstruktor kopiuj¹cy MainHeroObject";
	currentObjectTexture = tempHero->currentObjectTexture;

	HeroName = tempHero->HeroName;
	HeroHealthPoints = tempHero->HeroHealthPoints;
	Strength = tempHero->Strength, Intelligence = tempHero->Intelligence, Agility = tempHero->Agility;

	ScorePoints = tempHero->ScorePoints;
	CollectedChests = tempHero->CollectedChests;
	CollectedCoins = tempHero->CollectedCoins;
	SlayedEnemies = tempHero->SlayedEnemies;

	//cordsOfHero = tempHero->cordsOfHero;
	pointInGame.x = tempHero->pointInGame.x;
	pointInGame.y = tempHero->pointInGame.y;
	inputFromKeyboard = tempHero->inputFromKeyboard;
	textureNumber = tempHero->textureNumber;
	speedShift = tempHero->speedShift;

	return *this;
}

//Aktualizacja bohatera
void MainHeroObject::Update()
{
	BasicUpdate(); //Podstawowa funkcja z klasy interfejsu
	//std::cout << "cordsOfObject: " << cordsOfObject.x << " " << cordsOfObject.y << std::endl;
	destRect.x = pointInGame.x; //Punkt na mapie wzglêdem X
	destRect.y = pointInGame.y; //Punkt na mapie wzglêdem Y

	HandleKeyboard(); //Obs³uguj input z klawiatury, Poruszanie siê bohaterem
	currentObjectTexture = ImageTextureManager::LoadTexture(usableTextures[textureNumber]); //Podmiana tekstury w razie koniecznoœci
	if (textureNumber == 0) isMovingRight = true;
	else isMovingRight = false;
}

//Renderowanie bohatera
void MainHeroObject::Render()
{
	BasicRender(); //Podstawowa funkcja z klasy interfejsu
}
//PODSTAWOWE

void MainHeroObject::TeleportHeroToPoint(Point* point)
{
	pointInGame.x = point->x;
	pointInGame.y = point->y;
}

void MainHeroObject::ChangeHeroTexture_DamageOrHeal(bool damage)
{
	const char* tempHeroTexture = (const char*)currentObjectTexture;

	if (damage == true)
	{
		if (isMovingRight)
		{
			currentObjectTexture = ImageTextureManager::LoadTexture(usableTextures[2]);
		}
		else
		{
			currentObjectTexture = ImageTextureManager::LoadTexture(usableTextures[3]);
		}
	}
	else
	{
		if (isMovingRight)
		{
			currentObjectTexture = ImageTextureManager::LoadTexture(usableTextures[4]);
		}
		else
		{
			currentObjectTexture = ImageTextureManager::LoadTexture(usableTextures[5]);
		}
	}
}
