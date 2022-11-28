/*Pojedynczy punkt na osi xy.*/

#pragma once
class Point
{
public:
	Point();
	Point(int nx, int ny);
	Point(const Point& tempPoint);

	int x, y;
};

