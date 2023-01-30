#include "HeroObject.h"

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
	objTexture = tempHero.objTexture;
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

HeroObject& HeroObject::operator= (const HeroObject& tempHero) //Nie dzia³a?
{
	std::cout << "Konstruktor kopiuj¹cy HeroObject";
	objTexture = tempHero.objTexture;
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

HeroObject& HeroObject::operator= (HeroObject* tempHero) //Nie dzia³a?
{
	std::cout << "Konstruktor kopiuj¹cy HeroObject";
	objTexture = tempHero->objTexture;
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
	destRect.x = cordsOfHero.point.x; //Punkt na mapie wzglêdem X
	destRect.y = cordsOfHero.point.y; //Punkt na mapie wzglêdem Y
	MoveWithHero();
}

//Renderowanie bohatera
void HeroObject::Render()
{
	BasicRender(); //Podstawowa funkcja z klasy interfejsu
}
//PODSTAWOWE



//Poruszanie siê bohaterem
void HeroObject::MoveWithHero()
{
	// Obs³uguj input z klawiatury
	cordsOfHero = KeyboardManager::HandleKeyboard(cordsOfHero);

	//Podmiana tekstury w razie koniecznoœci
	objTexture = ImageTextureManager::LoadTexture(cordsOfHero.image);
}

void HeroObject::MoveHeroToPoint(Point* point)
{
	cordsOfHero.point.x = point->x;
	cordsOfHero.point.y = point->y;
}
