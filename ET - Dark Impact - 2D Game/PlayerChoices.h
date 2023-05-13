#pragma once
#include "iostream"

class PlayerChoices
{
public:
	PlayerChoices();

	enum TEST_GAME_MODE
	{
		INIT,
		START,
		STOPPED
	};

	enum RELATIONSHIP_WITH_MAGES
	{
		HATED = 1,
		BAD = 2,
		NEUTRAL = 3,
		GOOD = 4,
		LOVED = 5
	};

	TEST_GAME_MODE testGameMode;
	RELATIONSHIP_WITH_MAGES relationshipWithMages;
	unsigned __int8 relationMages;

	void setRelationshipWithMages();
};

