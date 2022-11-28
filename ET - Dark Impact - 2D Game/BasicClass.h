/*Klasa reprezentuj¹c¹ klasê postaci.*/

#pragma once
#include <string>
class BasicClass
{
public:
	std::string name;
	int MeleeAttack = 0, RangedAttack = 0, MagicAttack = 0;
	int MeleeDefense= 0, RangedDefense = 0, MagicDefense = 0;
	int Strength = 10, Intelligence = 10;
};

