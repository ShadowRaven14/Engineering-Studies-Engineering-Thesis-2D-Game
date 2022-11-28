#include "Point.h"

Point::Point()
{
	x = 0; y = 0;
}

Point::Point(int nx, int ny)
{
	x = nx; y = ny;
}

Point::Point(const Point& tempPoint)
{
	x = tempPoint.x;
	y = tempPoint.y;
}