/*Klasa poœrednia wspomagaj¹ca dzia³anie odczytywania z klawiatury.*/

#include "Point.h"

#pragma once
class CoordinatesOfHero 
	: public Point
{
public:
	CoordinatesOfHero();
	Point point; //pozycja na mapie wzglêdem osi xy
	char input; //obecny klawisz
	char previnput;	//wczeœniejszy klawisz
};

