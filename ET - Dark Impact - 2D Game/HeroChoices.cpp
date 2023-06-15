#include "HeroChoices.h"

HeroChoices::HeroChoices()
{
	testGameMode = HeroChoices::TEST_GAME_MODE::INIT;
	relationshipWithMages = HeroChoices::RELATIONSHIP_WITH_MAGES::MAGES_LOVED;
	relationshipWithSentinels = HeroChoices::RELATIONSHIP_WITH_SENTINELS::SENTINELS_LOVED;

	relationMages = relationshipWithMages;
	relationSentinels = relationshipWithSentinels;
}

void HeroChoices::setRelationshipWithMages()
{
	std::cout << "Changed relationship with Mages to: ";
	switch (relationMages)
	{
	case 1:
		relationshipWithMages = HeroChoices::RELATIONSHIP_WITH_MAGES::MAGES_HATED;
		std::cout << "MAGES_HATED" << std::endl;
		break;

	case 2:
		relationshipWithMages = HeroChoices::RELATIONSHIP_WITH_MAGES::MAGES_BAD;
		std::cout << "MAGES_BAD" << std::endl;
		break;

	case 3:
		relationshipWithMages = HeroChoices::RELATIONSHIP_WITH_MAGES::MAGES_NEUTRAL;
		std::cout << "MAGES_NEUTRAL" << std::endl;
		break;

	case 4:
		relationshipWithMages = HeroChoices::RELATIONSHIP_WITH_MAGES::MAGES_GOOD;
		std::cout << "MAGES_GOOD" << std::endl;
		break;

	case 5:
		relationshipWithMages = HeroChoices::RELATIONSHIP_WITH_MAGES::MAGES_LOVED;
		std::cout << "MAGES_LOVED" << std::endl;
		break;

	default:
		relationshipWithMages = HeroChoices::RELATIONSHIP_WITH_MAGES::MAGES_NEUTRAL;
		std::cout << "MAGES_NEUTRAL" << std::endl;
		break;
	}
}

void HeroChoices::setRelationshipWithSentinels()
{
	std::cout << "Changed relationship with Sentinels to: ";
	switch (relationSentinels)
	{
	case 1:
		relationshipWithSentinels = HeroChoices::RELATIONSHIP_WITH_SENTINELS::SENTINELS_HATED;
		std::cout << "SENTINELS_HATED" << std::endl;
		break;

	case 2:
		relationshipWithSentinels = HeroChoices::RELATIONSHIP_WITH_SENTINELS::SENTINELS_BAD;
		std::cout << "SENTINELS_BAD" << std::endl;
		break;

	case 3:
		relationshipWithSentinels = HeroChoices::RELATIONSHIP_WITH_SENTINELS::SENTINELS_NEUTRAL;
		std::cout << "SENTINELS_NEUTRAL" << std::endl;
		break;

	case 4:
		relationshipWithSentinels = HeroChoices::RELATIONSHIP_WITH_SENTINELS::SENTINELS_GOOD;
		std::cout << "SENTINELS_GOOD" << std::endl;
		break;

	case 5:
		relationshipWithSentinels = HeroChoices::RELATIONSHIP_WITH_SENTINELS::SENTINELS_LOVED;
		std::cout << "SENTINELS_LOVED" << std::endl;
		break;

	default:
		relationshipWithSentinels = HeroChoices::RELATIONSHIP_WITH_SENTINELS::SENTINELS_NEUTRAL;
		std::cout << "SENTINELS_NEUTRAL" << std::endl;
		break;
	}
}
