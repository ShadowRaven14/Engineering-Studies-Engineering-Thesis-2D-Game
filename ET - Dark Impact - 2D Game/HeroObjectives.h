/*Klasa reprezentuj¹ca cele gracza.*/

#pragma once
#include "BasicClass.h"

class HeroObjectives : public BasicClass
{
public:
	HeroObjectives();
	bool IsHeroAlive();
	bool HandleChestCollision(short worth);
	bool HandlePotionCollision(short power);
	bool HandleCoinCollision();
	bool HandleEnemyCollision(int power);
	void ShowCurrentObjectives();
	
	unsigned int ScorePoints;
	unsigned int CollectedChests;
	unsigned int CollectedCoins;
	unsigned int SlayedEnemies;
};

