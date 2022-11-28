/*Klasa poœrednia wspomagaj¹ca dzia³anie odczytywania z klawiatury.*/

#include "Point.h"

#pragma once
class PointInMap 
	: public Point
{
public:
	PointInMap();
	Point point; //pozycja na mapie wzglêdem osi xy
	//int xpos; //pozycja na mapie wzglêdem osi x
	//int ypos; //pozycja na mapie wzglêdem osi y
	char input; //obecny klawisz
	char previnput;	//wczeœniejszy klawisz
};

