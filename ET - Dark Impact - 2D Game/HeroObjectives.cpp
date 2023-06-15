#include "HeroObjectives.h"

HeroObjectives::HeroObjectives()
{
	ScorePoints = 0;
	CollectedChests = 0;
	CollectedCoins = 0;
	SlayedEnemies = 0;
}

bool HeroObjectives::IsHeroAlive()
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

bool HeroObjectives::HandleEnemyCollision(int power)
{
	if (Strength > power)
	{
		ScorePoints = ScorePoints + (power * 10);
		SlayedEnemies++;
		return true;
	}
	else
	{
		Game::isGameRunning = IsHeroAlive();
		return false;
	}

	//ShowCurrentObjectives();
	return false;
}

bool HeroObjectives::HandleChestCollision(short worth)
{
	CollectedChests++;
	ScorePoints = ScorePoints + (worth * 10);

	int r = rand() % 3;
	switch (r)
	{
	case 0:
		Strength = Strength + worth;
		
		break;

	case 1:
		Intelligence = Intelligence + worth;
		break;

	case 2:
		Agility = Agility + worth;
		break;

	default:
		break;
	}

	CurrentStatistics();
	//ShowCurrentObjectives();
	return true;
}

bool HeroObjectives::HandleAppleCollision(short power)
{
	HeroHealthPoints = HeroHealthPoints + power;
	std::cout << "HeroHealthPoints: " << HeroHealthPoints << std::endl;

	//ShowCurrentObjectives();
	return true;
}

bool HeroObjectives::HandleCoinCollision(short power)
{
	CollectedCoins++;
	ScorePoints = ScorePoints + 10;
	std::cout << "ScorePoints: " << ScorePoints << std::endl;

	//ShowCurrentObjectives();
	return true;
}

bool HeroObjectives::HandlePotionCollision(short power)
{
	HeroHealthPoints = HeroHealthPoints + power;
	std::cout << "HeroHealthPoints: " << HeroHealthPoints << std::endl;

	int r = rand() % 3;
	switch (r)
	{
	case 0:
		Strength = Strength + 1;
		
		break;

	case 1:
		Intelligence = Intelligence + 1;
		break;

	case 2:
		Agility = Agility + 1;
		break;

	default:
		break;
	}

	//ShowCurrentObjectives();
	return true;
}


void HeroObjectives::ShowCurrentObjectives()
{
	std::cout << "- - - Objectives - - -" << std::endl;
	std::cout << "HeroHealthPoints: " << HeroHealthPoints << std::endl;
	std::cout << "ScorePoints: " << ScorePoints << std::endl;
	std::cout << "CollectedChests: " << CollectedChests << std::endl;
	std::cout << "CollectedCoins: " << CollectedCoins << std::endl;
	std::cout << "SlayedEnemies: " << SlayedEnemies << std::endl;
	std::cout << "- - - - - - - - - - -" << std::endl;
}