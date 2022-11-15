#pragma once
#include "Game.h"
#include "PointInMap.h"

class KeyboardManager
{
public:
	static PointInMap HandleKeyboard(PointInMap point); //Obsługa klawiatury
	char input; //obecny klawisz
	char previnput; //wcześniejszy klawisz
};

