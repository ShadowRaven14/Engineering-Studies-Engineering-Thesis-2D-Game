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
		tempTex = "Images/AppleNormal.png";
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

HeroObject::HeroObject(const HeroObject& tempHero) //Nie dzia�a?
{
	std::cout << "Konstruktor kopiuj�cy HeroObject";
	currentObjectTexture = tempHero.currentObjectTexture;
	cordsOfHero = tempHero.cordsOfHero;

	HeroName = tempHero.HeroName;
	HeroHealthPoints = tempHero.HeroHealthPoints;
	MeleeAttack = tempHero.MeleeAttack, RangedAttack = tempHero.RangedAttack, MagicAttack = tempHero.MagicAttack;
	MeleeDefense = tempHero.MeleeDefense, RangedDefense = tempHero.RangedDefense, MagicDefense = tempHero.MagicDefense;
	Strength = tempHero.Strength, Intelligence = tempHero.Intelligence, Agility = tempHero.Agility;

	ScorePoints = tempHero.ScorePoints;
	CollectedChests = tempHero.CollectedChests;
	CollectedCoins = tempHero.CollectedCoins;
	SlayedEnemies = tempHero.SlayedEnemies;
}

HeroObject& HeroObject::operator= (const HeroObject& tempHero) //Nie dzia�a?
{
	std::cout << "Konstruktor kopiuj�cy HeroObject";
	currentObjectTexture = tempHero.currentObjectTexture;
	cordsOfHero = tempHero.cordsOfHero;

	HeroName = tempHero.HeroName;
	HeroHealthPoints = tempHero.HeroHealthPoints;
	MeleeAttack = tempHero.MeleeAttack, RangedAttack = tempHero.RangedAttack, MagicAttack = tempHero.MagicAttack;
	MeleeDefense = tempHero.MeleeDefense, RangedDefense = tempHero.RangedDefense, MagicDefense = tempHero.MagicDefense;
	Strength = tempHero.Strength, Intelligence = tempHero.Intelligence, Agility = tempHero.Agility;

	ScorePoints = tempHero.ScorePoints;
	CollectedChests = tempHero.CollectedChests;
	CollectedCoins = tempHero.CollectedCoins;
	SlayedEnemies = tempHero.SlayedEnemies;

	return *this;
}

HeroObject& HeroObject::operator= (HeroObject* tempHero) //Nie dzia�a?
{
	std::cout << "Konstruktor kopiuj�cy HeroObject";
	currentObjectTexture = tempHero->currentObjectTexture;
	cordsOfHero = tempHero->cordsOfHero;

	HeroName = tempHero->HeroName;
	HeroHealthPoints = tempHero->HeroHealthPoints;
	MeleeAttack = tempHero->MeleeAttack, RangedAttack = tempHero->RangedAttack, MagicAttack = tempHero->MagicAttack;
	MeleeDefense = tempHero->MeleeDefense, RangedDefense = tempHero->RangedDefense, MagicDefense = tempHero->MagicDefense;
	Strength = tempHero->Strength, Intelligence = tempHero->Intelligence, Agility = tempHero->Agility;

	ScorePoints = tempHero->ScorePoints;
	CollectedChests = tempHero->CollectedChests;
	CollectedCoins = tempHero->CollectedCoins;
	SlayedEnemies = tempHero->SlayedEnemies;

	return *this;
}

//Aktualizacja bohatera
void HeroObject::Update()
{
	BasicUpdate(); //Podstawowa funkcja z klasy interfejsu
	destRect.x = cordsOfHero.point.x; //Punkt na mapie wzgl�dem X
	destRect.y = cordsOfHero.point.y; //Punkt na mapie wzgl�dem Y
	MoveWithHero();
}

//Renderowanie bohatera
void HeroObject::Render()
{
	BasicRender(); //Podstawowa funkcja z klasy interfejsu
}
//PODSTAWOWE



//Poruszanie si� bohaterem
void HeroObject::MoveWithHero()
{
	// Obs�uguj input z klawiatury
	cordsOfHero = KeyboardManager::HandleKeyboard(cordsOfHero);

	//Podmiana tekstury w razie konieczno�ci
	currentObjectTexture = ImageTextureManager::LoadTexture(usableTextures[cordsOfHero.ntexture]);
}

void HeroObject::MoveHeroToPoint(Point* point)
{
	cordsOfHero.point.x = point->x;
	cordsOfHero.point.y = point->y;
}
