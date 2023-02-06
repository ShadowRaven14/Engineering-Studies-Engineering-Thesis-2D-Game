/*Klasa reprezentuj¹ca cele gracza.*/

#pragma once
#include "BasicClass.h"

class HeroStatistics : public BasicClass
{
public:
	HeroStatistics();
	bool IsHeroAlive();
	bool HandleEnemyCollision(int power);
	bool HandleChestCollision(short worth);
	bool HandleCoinCollision();
	void ShowCurrentStatistics();
	
	unsigned int ScorePoints;
	unsigned int CollectedChests;
	unsigned int CollectedCoins;
	unsigned int SlayedEnemies;
};

