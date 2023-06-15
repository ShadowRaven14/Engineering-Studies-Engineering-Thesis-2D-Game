/*Klasa reprezentuj¹ca cele gracza.*/

#pragma once
#include "HeroBasicClass.h"

class HeroObjectives : public HeroBasicClass
{
public:
	HeroObjectives();
	bool IsHeroAlive();

	bool HandleTeleportCollision(short challenge);
	bool HandleChestCollision(short worth);

	bool HandleAppleCollision(short power);
	bool HandleCoinCollision(short power);
	bool HandlePotionCollision(short power);

	bool HandleEnemyCollision(int power);

	void ShowCurrentObjectives();
	
	unsigned int ScorePoints;
	unsigned int CollectedChests;
	unsigned int CollectedCoins;
	unsigned int SlayedEnemies;
};

