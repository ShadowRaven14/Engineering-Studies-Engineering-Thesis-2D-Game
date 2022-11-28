/*Klasa zajmuj¹ca siê pobieraniem znaków z klawiatury.
Przechowuje obecny i wczeœniej naciœniêty klawisz.*/

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

