/*Klasa zajmuj�ca si� pobieraniem znak�w z klawiatury.
Przechowuje obecny i wcze�niej naci�ni�ty klawisz.*/

#pragma once
#include "Game.h"
#include "Point.h"


class HeroKeyboardHandler
{
public:
	HeroKeyboardHandler();
	void HandleKeyboard(); //Obs�uga klawiatury

	Point pointInMap; //pozycja na mapie wzgl�dem osi xy
	char inputFromKeyboard; //obecny klawisz
	short textureNumber; //numer tekstory
	int speedShift; //szybko�� postaci
};

