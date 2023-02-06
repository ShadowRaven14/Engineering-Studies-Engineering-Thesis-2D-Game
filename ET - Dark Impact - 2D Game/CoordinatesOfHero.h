/*Klasa poœrednia wspomagaj¹ca dzia³anie odczytywania z klawiatury.*/

#include "Point.h"
#include <string>

#pragma once
class CoordinatesOfHero 
	: public Point
{
public:
	CoordinatesOfHero();
	Point point; //pozycja na mapie wzglêdem osi xy
	char input; //obecny klawisz
	short ntexture;
};

