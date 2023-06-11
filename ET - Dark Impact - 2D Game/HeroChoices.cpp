#include "HeroChoices.h"

HeroChoices::HeroChoices()
{
	testGameMode = HeroChoices::TEST_GAME_MODE::INIT;
	relationshipWithMages = HeroChoices::RELATIONSHIP_WITH_MAGES::LOVED;
	relationMages = relationshipWithMages;
}

void HeroChoices::setRelationshipWithMages()
{
	std::cout << "Changed relationship with Mages to: ";
	switch (relationMages)
	{
	case 1:
		relationshipWithMages = HeroChoices::RELATIONSHIP_WITH_MAGES::HATED;
		std::cout << "HATED" << std::endl;
		break;

	case 2:
		relationshipWithMages = HeroChoices::RELATIONSHIP_WITH_MAGES::BAD;
		std::cout << "BAD" << std::endl;
		break;

	case 3:
		relationshipWithMages = HeroChoices::RELATIONSHIP_WITH_MAGES::NEUTRAL;
		std::cout << "NEUTRAL" << std::endl;
		break;

	case 4:
		relationshipWithMages = HeroChoices::RELATIONSHIP_WITH_MAGES::GOOD;
		std::cout << "GOOD" << std::endl;
		break;

	case 5:
		relationshipWithMages = HeroChoices::RELATIONSHIP_WITH_MAGES::LOVED;
		std::cout << "LOVED" << std::endl;
		break;

	default:
		relationshipWithMages = HeroChoices::RELATIONSHIP_WITH_MAGES::NEUTRAL;
		std::cout << "NEUTRAL" << std::endl;
		break;
	}
}

