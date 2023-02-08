/*Klasa zajmuj¹ca siê pobieraniem znaków z klawiatury.
Przechowuje obecny i wczeœniej naciœniêty klawisz.*/

#pragma once
#include "Game.h"
#include "Point.h"


class HeroKeyboardHandler
{
public:
	HeroKeyboardHandler();
	void HandleKeyboard(); //Obs³uga klawiatury

	Point pointInMap; //pozycja na mapie wzglêdem osi xy
	char inputFromKeyboard; //obecny klawisz
	short textureNumber; //numer tekstory
	int speedShift; //szybkoœæ postaci
};

