//Point2D.cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include "Point2D.h"

Point2D::Point2D()
{
	x = 0;
	y = 0;
}

Point2D::Point2D(float a, float b)
{
	x = a;
	y = b;
}

bool Point2D::operator== (const Point2D& rhs)
{
	return x==rhs.x && y==rhs.y;
}