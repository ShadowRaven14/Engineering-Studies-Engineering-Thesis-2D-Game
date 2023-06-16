#include "HeroBasicClass.h"

HeroBasicClass::HeroBasicClass()
{
	HeroName = "Hero";
	HeroHealthPoints = 25;
	Strength = 10, Intelligence = 10, Agility = 10;

	ScorePoints = 0;
	CollectedChests = 0;
	CollectedCoins = 0;
	SlayedEnemies = 0;
}

void HeroBasicClass::CurrentStatistics()
{
	std::cout << std::endl;
	std::cout << "- - - Objectives - - -" << std::endl;
	std::cout << "Strength: " << Strength << std::endl;
	std::cout << "Agility: " << Agility << std::endl;
	std::cout << "Intelligence: " << Intelligence << std::endl;
	std::cout << "- - - - - - - - - - -" << std::endl;

	std::cout << "- - - Objectives - - -" << std::endl;
	std::cout << "HeroHealthPoints: " << HeroHealthPoints << std::endl;
	std::cout << "ScorePoints: " << ScorePoints << std::endl;
	std::cout << "CollectedChests: " << CollectedChests << std::endl;
	std::cout << "CollectedCoins: " << CollectedCoins << std::endl;
	std::cout << "SlayedEnemies: " << SlayedEnemies << std::endl;
	std::cout << "- - - - - - - - - - -" << std::endl;
	std::cout << std::endl;
}

bool HeroBasicClass::IsHeroAlive()
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

bool HeroBasicClass::HandleEnemyCollision(unsigned short power)
{
	std::cout << "Challenge Strength: " << power << std::endl;

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

	//CurrentStatistics();
	return false;
}

bool HeroBasicClass::HandleTeleportCollision(unsigned short challenge)
{
	std::cout << "Challenge Intelligence: " << challenge << std::endl;

	if (Intelligence > challenge)
	{
		return true;
	}

	//CurrentStatistics();
	return false;
}

bool HeroBasicClass::HandleChestCollision(unsigned short challenge)
{
	std::cout << "Challenge Agility: " << challenge << std::endl;

	CollectedChests++;
	ScorePoints = ScorePoints + (challenge * 5);

	int r = rand() % 3;
	if (Agility > challenge * 2)
	{
		switch (r)
		{
		case 0:
			Strength = Strength + challenge;

			break;

		case 1:
			Intelligence = Intelligence + challenge;
			break;

		case 2:
			Agility = Agility + challenge;
			break;

		default:
			break;
		}

		//CurrentStatistics();
		return true;
	}

	//CurrentStatistics();
	return false;
}

bool HeroBasicClass::HandleAppleCollision(unsigned short power)
{
	HeroHealthPoints = HeroHealthPoints + power;
	std::cout << "HeroHealthPoints: " << HeroHealthPoints << std::endl;

	//CurrentStatistics();
	return true;
}

bool HeroBasicClass::HandleCoinCollision(unsigned short power)
{
	CollectedCoins++;
	ScorePoints = ScorePoints + 10;
	std::cout << "ScorePoints: " << ScorePoints << std::endl;

	//CurrentStatistics();
	return true;
}

bool HeroBasicClass::HandlePotionCollision(unsigned short power)
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

	//CurrentStatistics();
	return true;
}