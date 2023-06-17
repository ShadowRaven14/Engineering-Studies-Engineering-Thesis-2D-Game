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
	bool HandlePotionCollision(unsigned short power, unsigned short n);


	std::string HeroName = "Hero";
	unsigned short HeroHealthPoints = 25;
	unsigned short Strength = 10, Agility = 10, Intelligence = 10;

	unsigned int ScorePoints = 0;
	unsigned short CollectedChests = 0;
	unsigned short CollectedCoins = 0;
	unsigned short SlayedEnemies = 0;
};

