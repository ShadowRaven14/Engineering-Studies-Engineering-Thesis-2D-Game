#include "HeroStatistics.h"

HeroStatistics::HeroStatistics()
{
	ScorePoints = 0;
	CollectedChests = 0;
	CollectedCoins = 0;
	SlayedEnemies = 0;
}

bool HeroStatistics::IsHeroAlive()
{
	if (HeroHealthPoints <= 10)
	{
		std::cout << "You have low HP... " << HeroHealthPoints << std::endl;
		if (HeroHealthPoints <= 0)
		{
			std::cout << "YOU HAVE DIED..." << std::endl;
			return false;
		}
	}
	return true;
}

bool HeroStatistics::HandleEnemyCollision(int power)
{
	if (Strength > power)
	{
		std::cout << "Enemy slayed!" << std::endl;
		ScorePoints = ScorePoints + (power * 10);
		SlayedEnemies++;
		return true;
	}
	else
	{
		HeroHealthPoints = HeroHealthPoints - 1;
		Game::isGameRunning = IsHeroAlive();
	}

	//ShowCurrentStatistics();
	return false;
}

bool HeroStatistics::HandleChestCollision(short worth)
{
	CollectedChests++;
	ScorePoints = ScorePoints + (worth * 10);

	int r = rand() % 3;
	switch (r)
	{
	case 0:
		Agility = Agility + worth;
		break;

	case 1:
		Strength = Strength + worth;
		break;

	case 2:
		Intelligence = Intelligence + worth;
		break;

	default:
		break;
	}

	CurrentStatistics();
	//ShowCurrentStatistics();
	return true;
}

bool HeroStatistics::HandlePotionCollision(short power)
{
	HeroHealthPoints = HeroHealthPoints + power;
	std::cout << HeroHealthPoints << std::endl;
	return true;
}

bool HeroStatistics::HandleCoinCollision()
{
	CollectedCoins++;
	ScorePoints = ScorePoints + 10;

	ShowCurrentStatistics();
	return true;
}


void HeroStatistics::ShowCurrentStatistics()
{
	std::cout << "- - - Objectives - - -" << std::endl;
	std::cout << "HeroHealthPoints: " << HeroHealthPoints << std::endl;
	std::cout << "ScorePoints: " << ScorePoints << std::endl;
	std::cout << "CollectedChests: " << CollectedChests << std::endl;
	std::cout << "CollectedCoins: " << CollectedCoins << std::endl;
	std::cout << "SlayedEnemies: " << SlayedEnemies << std::endl;
	std::cout << "- - - - - - - - - - -" << std::endl;
}