#include "PlayerChoices.h"

PlayerChoices::PlayerChoices()
{
	testGameMode = PlayerChoices::TEST_GAME_MODE::INIT;
	relationshipWithMages = PlayerChoices::RELATIONSHIP_WITH_MAGES::LOVED;
	relationMages = relationshipWithMages;
}

void PlayerChoices::setRelationshipWithMages()
{
	std::cout << "Changed relationship with Mages to: ";
	switch (relationMages)
	{
	case 1:
		relationshipWithMages = PlayerChoices::RELATIONSHIP_WITH_MAGES::HATED;
		std::cout << "HATED" << std::endl;
		break;

	case 2:
		relationshipWithMages = PlayerChoices::RELATIONSHIP_WITH_MAGES::BAD;
		std::cout << "BAD" << std::endl;
		break;

	case 3:
		relationshipWithMages = PlayerChoices::RELATIONSHIP_WITH_MAGES::NEUTRAL;
		std::cout << "NEUTRAL" << std::endl;
		break;

	case 4:
		relationshipWithMages = PlayerChoices::RELATIONSHIP_WITH_MAGES::GOOD;
		std::cout << "GOOD" << std::endl;
		break;

	case 5:
		relationshipWithMages = PlayerChoices::RELATIONSHIP_WITH_MAGES::LOVED;
		std::cout << "LOVED" << std::endl;
		break;

	default:
		relationshipWithMages = PlayerChoices::RELATIONSHIP_WITH_MAGES::NEUTRAL;
		std::cout << "NEUTRAL" << std::endl;
		break;
	}
}

