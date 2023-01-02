#include "GameObjective.h"

GameObjective::GameObjective()
{
	HeroHealthPoints = 50;
	ScorePoints = 0;
	CollectedChests = 0;
	CollectedCoins = 0;
	SlayedEnemies = 0;
}

void GameObjective::CurrentScorePoints()
{
	//std::cout << "- - - Objectives - - -" << std::endl;
	//std::cout << "HeroHealthPoints: " << HeroHealthPoints << std::endl;
	//std::cout << "ScorePoints: " << ScorePoints << std::endl;
	//std::cout << "CollectedChests: " << CollectedChests << std::endl;
	//std::cout << "CollectedCoins: " << CollectedCoins << std::endl;
	//std::cout << "SlayedEnemies: " << SlayedEnemies << std::endl;
	//std::cout << "- - - - - - - - - - -" << std::endl;
}