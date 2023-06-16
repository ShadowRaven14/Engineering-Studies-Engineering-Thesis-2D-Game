/*Klasa reprezentuj¹c¹ klasê postaci.*/

#pragma once
#include "Game.h"

class HeroBasicClass
{
public:
	HeroBasicClass();
	void CurrentStatistics();
	bool IsHeroAlive();

	bool HandleEnemyCollision(unsigned short power);

	bool HandleTeleportCollision(unsigned short challenge);
	bool HandleChestCollision(unsigned short challenge);

	bool HandleAppleCollision(unsigned short power);
	bool HandleCoinCollision(unsigned short power);
	bool HandlePotionCollision(unsigned short power);


	std::string HeroName;
	unsigned short HeroHealthPoints;
	unsigned short Strength, Agility, Intelligence;

	unsigned int ScorePoints;
	unsigned short CollectedChests;
	unsigned short CollectedCoins;
	unsigned short SlayedEnemies;
};

