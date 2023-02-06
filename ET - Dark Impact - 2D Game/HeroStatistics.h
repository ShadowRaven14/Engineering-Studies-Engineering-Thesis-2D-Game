/*Klasa reprezentuj¹ca cele gracza.*/

#pragma once
#include "BasicClass.h"

class HeroStatistics : public BasicClass
{
public:
	HeroStatistics();
	bool IsHeroAlive();
	bool HandleChestCollision(short worth);
	bool HandlePotionCollision(short power);
	bool HandleCoinCollision();
	bool HandleEnemyCollision(int power);
	void ShowCurrentStatistics();
	
	unsigned int ScorePoints;
	unsigned int CollectedChests;
	unsigned int CollectedCoins;
	unsigned int SlayedEnemies;
};

