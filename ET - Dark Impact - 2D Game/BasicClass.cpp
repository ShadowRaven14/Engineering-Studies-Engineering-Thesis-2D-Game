#include "BasicClass.h"

BasicClass::BasicClass()
{
	HeroName = "Hero";
	HeroHealthPoints = 25;
	MeleeAttack = 0, RangedAttack = 0, MagicAttack = 0;
	MeleeDefense = 0, RangedDefense = 0, MagicDefense = 0;
	Strength = 10, Intelligence = 10, Agility = 10;
}

void BasicClass::CurrentStatistics()
{
	std::cout << "- - - Objectives - - -" << std::endl;
	std::cout << "Strength: " << Strength << std::endl;
	std::cout << "Agility: " << Agility << std::endl;
	std::cout << "Intelligence: " << Intelligence << std::endl;
	std::cout << "- - - - - - - - - - -" << std::endl;
}