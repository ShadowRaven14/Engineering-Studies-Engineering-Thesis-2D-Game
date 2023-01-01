/*Klasa reprezentuj¹ca cele gracza.*/

#pragma once
#include <iostream>

class GameObjective
{
public:
	GameObjective();
	void CurrentScorePoints();
	
	int HeroHealthPoints;
	unsigned int ScorePoints;
	unsigned int CollectedChests;
	unsigned int CollectedCoins;
	unsigned int SlayedEnemies;
};

