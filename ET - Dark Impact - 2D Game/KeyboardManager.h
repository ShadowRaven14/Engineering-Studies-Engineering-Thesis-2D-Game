#pragma once
#include "Game.h"
#include "PointInMap.h"

class KeyboardManager
{
public:
	static PointInMap HandleKeyboard(PointInMap point); //Obs³uga klawiatury
	char input; //obecny klawisz
	char previnput; //wczeœniejszy klawisz
};

