/*Klasa reprezentuj�c� klas� postaci.*/

#pragma once
#include "Game.h"

class HeroBasicClass
{
public:
	HeroBasicClass();
	void CurrentStatistics();

	std::string HeroName;
	int HeroHealthPoints;
	int Strength, Intelligence, Agility;
};

