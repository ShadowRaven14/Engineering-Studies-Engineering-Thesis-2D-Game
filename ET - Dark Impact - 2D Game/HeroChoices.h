#pragma once
#include "iostream"

class HeroChoices
{
public:
	HeroChoices();

	enum TEST_GAME_MODE
	{
		INIT,
		START,
		STOPPED
	};

	enum RELATIONSHIP_WITH_MAGES
	{
		MAGES_HATED = 1,
		MAGES_BAD = 2,
		MAGES_NEUTRAL = 3,
		MAGES_GOOD = 4,
		MAGES_LOVED = 5
	};

	enum RELATIONSHIP_WITH_SENTINELS
	{
		SENTINELS_HATED = 1,
		SENTINELS_BAD = 2,
		SENTINELS_NEUTRAL = 3,
		SENTINELS_GOOD = 4,
		SENTINELS_LOVED = 5
	};

	TEST_GAME_MODE testGameMode;
	RELATIONSHIP_WITH_MAGES relationshipWithMages;
	RELATIONSHIP_WITH_SENTINELS relationshipWithSentinels;

	unsigned __int8 relationMages;
	unsigned __int8 relationSentinels;

	void setRelationshipWithMages();
	void setRelationshipWithSentinels();
};

