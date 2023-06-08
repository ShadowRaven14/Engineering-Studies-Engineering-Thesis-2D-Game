#include "HeroObject.h"

HeroObject::HeroObject(unsigned short type)
{
	const char* tempTex;

	switch (type)
	{
	case 0:
		tempTex = "Images/ElvenTracker_GoRight.png";
		usableTextures.push_back(tempTex);
		tempTex = "Images/ElvenTracker_GoLeft.png";
		usableTextures.push_back(tempTex);
		tempTex = "Images/_blank.png";
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
HeroObject::HeroObject(const char* texturesheet, int x, int y)
{
	BasicInit(texturesheet, x, y); //Podstawowa funkcja z klasy interfejsu
}

//Konstruktor bohatera
HeroObject::HeroObject(const char* texturesheet, Point* point)
{
	BasicInit(texturesheet, point->x, point->y); //Podstawowa funkcja z klasy interfejsu
}

HeroObject::HeroObject(const HeroObject& tempHero) //Nie dzia³a?
{
	std::cout << "Konstruktor kopiuj¹cy HeroObject";
	currentObjectTexture = tempHero.currentObjectTexture;

	HeroName = tempHero.HeroName;
	HeroHealthPoints = tempHero.HeroHealthPoints;
	MeleeAttack = tempHero.MeleeAttack, RangedAttack = tempHero.RangedAttack, MagicAttack = tempHero.MagicAttack;
	MeleeDefense = tempHero.MeleeDefense, RangedDefense = tempHero.RangedDefense, MagicDefense = tempHero.MagicDefense;
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

HeroObject& HeroObject::operator= (const HeroObject& tempHero) //Nie dzia³a?
{
	std::cout << "Konstruktor kopiuj¹cy HeroObject";
	currentObjectTexture = tempHero.currentObjectTexture;

	HeroName = tempHero.HeroName;
	HeroHealthPoints = tempHero.HeroHealthPoints;
	MeleeAttack = tempHero.MeleeAttack, RangedAttack = tempHero.RangedAttack, MagicAttack = tempHero.MagicAttack;
	MeleeDefense = tempHero.MeleeDefense, RangedDefense = tempHero.RangedDefense, MagicDefense = tempHero.MagicDefense;
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

HeroObject& HeroObject::operator= (HeroObject* tempHero) //Nie dzia³a?
{
	std::cout << "Konstruktor kopiuj¹cy HeroObject";
	currentObjectTexture = tempHero->currentObjectTexture;

	HeroName = tempHero->HeroName;
	HeroHealthPoints = tempHero->HeroHealthPoints;
	MeleeAttack = tempHero->MeleeAttack, RangedAttack = tempHero->RangedAttack, MagicAttack = tempHero->MagicAttack;
	MeleeDefense = tempHero->MeleeDefense, RangedDefense = tempHero->RangedDefense, MagicDefense = tempHero->MagicDefense;
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
void HeroObject::Update()
{
	BasicUpdate(); //Podstawowa funkcja z klasy interfejsu
	//std::cout << "cordsOfObject: " << cordsOfObject.x << " " << cordsOfObject.y << std::endl;
	destRect.x = pointInGame.x; //Punkt na mapie wzglêdem X
	destRect.y = pointInGame.y; //Punkt na mapie wzglêdem Y

	HandleKeyboard(); //Obs³uguj input z klawiatury, Poruszanie siê bohaterem
	currentObjectTexture = ImageTextureManager::LoadTexture(usableTextures[textureNumber]); //Podmiana tekstury w razie koniecznoœci
}

//Renderowanie bohatera
void HeroObject::Render()
{
	BasicRender(); //Podstawowa funkcja z klasy interfejsu
}
//PODSTAWOWE

void HeroObject::TeleportHeroToPoint(Point* point)
{
	pointInGame.x = point->x;
	pointInGame.y = point->y;
}
