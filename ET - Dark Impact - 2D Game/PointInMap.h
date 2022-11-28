/*Klasa pośrednia wspomagająca działanie odczytywania z klawiatury.*/

#include "Point.h"

#pragma once
class PointInMap 
	: public Point
{
public:
	PointInMap();
	Point point; //pozycja na mapie względem osi xy
	//int xpos; //pozycja na mapie względem osi x
	//int ypos; //pozycja na mapie względem osi y
	char input; //obecny klawisz
	char previnput;	//wcześniejszy klawisz
};

