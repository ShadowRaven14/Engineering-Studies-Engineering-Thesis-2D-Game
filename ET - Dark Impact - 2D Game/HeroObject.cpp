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

HeroObject::HeroObject(const HeroObject& tempHero) //Nie dzia�a?
{
	std::cout << "Konstruktor kopiuj�cy HeroObject";
	objTexture = tempHero.objTexture;
	cordsOfObject = tempHero.cordsOfObject;

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
	objTexture = tempHero.objTexture;
	cordsOfObject = tempHero.cordsOfObject;

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
	objTexture = tempHero->objTexture;
	cordsOfObject = tempHero->cordsOfObject;

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
	cordsOfObject = KeyboardManager::HandleKeyboard(cordsOfObject);

	// OBS�UGA PORUSZANIA
	// WHILE MOVING DOWN
	if (cordsOfObject.input == 's')
	{
		if (cordsOfObject.input == 'a')		// Id� w lewo
			cordsOfObject.previnput = 'a';
		else if (cordsOfObject.input == 'd')	// Id� w prawo
			cordsOfObject.previnput = 'd';
	}
	// WHILE MOVING UP
	else if (cordsOfObject.input == 'w')
	{
		if (cordsOfObject.input == 'a')		// Id� w lewo
			cordsOfObject.previnput = 'a';
		else if (cordsOfObject.input == 'd')	// Id� w prawo
			cordsOfObject.previnput = 'd';
	}
	// WHILE MOVING RIGHT
	else if (cordsOfObject.input == 'd')
	{
		if (cordsOfObject.input == 'w')		// Id� w g�r�
			cordsOfObject.previnput = 'w';
		else if (cordsOfObject.input == 's')	// Id� w d�
			cordsOfObject.previnput = 's';
	}
	// WHILE MOVING LEFT
	else if (cordsOfObject.input == 'a')
	{
		if (cordsOfObject.input == 'w')		// Id� w g�re
			cordsOfObject.previnput = 'w';
		else if (cordsOfObject.input == 's')	// Id� w d�
			cordsOfObject.previnput = 's';
	}
}

void HeroObject::MoveHeroToPoint(Point* point)
{
	cordsOfObject.point.x = point->x;
	cordsOfObject.point.y = point->y;
}
