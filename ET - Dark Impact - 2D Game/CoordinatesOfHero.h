/*Klasa po�rednia wspomagaj�ca dzia�anie odczytywania z klawiatury.*/

#include "Point.h"
#include <string>

#pragma once
class CoordinatesOfHero 
	: public Point
{
public:
	CoordinatesOfHero();
	Point point; //pozycja na mapie wzgl�dem osi xy
	char input; //obecny klawisz
	short ntexture;
};

