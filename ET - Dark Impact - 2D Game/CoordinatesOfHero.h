/*Klasa pośrednia wspomagająca działanie odczytywania z klawiatury.*/

#include "Point.h"
#include <string>

#pragma once
class CoordinatesOfHero 
	: public Point
{
public:
	CoordinatesOfHero();
	Point point; //pozycja na mapie względem osi xy
	char input; //obecny klawisz
	const char* image;
};

