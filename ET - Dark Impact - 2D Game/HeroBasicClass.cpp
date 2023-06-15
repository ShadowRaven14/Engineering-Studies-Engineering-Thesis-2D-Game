#include "HeroBasicClass.h"

HeroBasicClass::HeroBasicClass()
{
	HeroName = "Hero";
	HeroHealthPoints = 25;
	Strength = 10, Intelligence = 10, Agility = 10;
}

void HeroBasicClass::CurrentStatistics()
{
	std::cout << "- - - Objectives - - -" << std::endl;
	std::cout << "Strength: " << Strength << std::endl;
	std::cout << "Agility: " << Agility << std::endl;
	std::cout << "Intelligence: " << Intelligence << std::endl;
	std::cout << "- - - - - - - - - - -" << std::endl;
}