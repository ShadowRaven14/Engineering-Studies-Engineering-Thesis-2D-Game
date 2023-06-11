/*Klasa reprezentuj¹c¹ klasê postaci.*/

#pragma once
#include "Game.h"

class HeroBasicClass
{
public:
	HeroBasicClass();
	void CurrentStatistics();

	std::string HeroName;
	int HeroHealthPoints;
	int MeleeAttack, RangedAttack, MagicAttack;
	int MeleeDefense, RangedDefense, MagicDefense;
	int Strength, Intelligence, Agility;
};

