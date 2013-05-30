//Rectangle.cpp
/* Specification:
		Design and Implement a C++ program that implements the following:
			- 2D Rectangle Class with floating point coordinates.
			- Methods for constructing a Rectangle with initial size and coordinates
			- Copy and Assignment constructors/operators
			- Method in the Class that allows you to check for collision between two axis-aligned Rectangles.
			- Method for testing collision/intersection with a 2D point
			- Simple test code that creates instances of your class and tests your implementation
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include "Rectangle.h"

using namespace std;
inline void keep_window_open() {char ch; cin>>ch;}

// Method for constructing rectangles using width, height, initial point (bottom left corner)
Rectangle::Rectangle(float Width, float Height, float X, float Y)
{
	width = Width;
	height = Height;
	bottomLeft = Point2D(X, Y);
	bottomRight = Point2D(X+Width, Y);
	topLeft = Point2D(X, Y+Height);
	topRight = Point2D(X+Width, Y+Height);
}

// Method for constructing rectangles using two points
Rectangle::Rectangle(Point2D& pOne, Point2D& pTwo)
{
	width = abs(pOne.getX() - pTwo.getX());
	height = abs(pOne.getY() - pTwo.getY());

	// Find the coordinates of the rectangle
	if (pOne.getX() <= pTwo.getX())
	{
		if (pOne.getY() <= pTwo.getY())
		{
			bottomLeft = pOne;
			topRight = pTwo;
			bottomRight = Point2D(topRight.getX(), bottomLeft.getY());
			topLeft = Point2D(bottomLeft.getX(), topRight.getY());
		} else {
			topLeft = pOne;
			bottomRight = pTwo;
			bottomLeft = Point2D(topLeft.getX(), bottomRight.getY());
			topRight = Point2D(bottomRight.getX(), topLeft.getY());
		}
	} else {
		if (pOne.getY() <= pTwo.getY())
		{
			bottomRight = pOne;
			topLeft = pTwo;
			bottomLeft = Point2D(topLeft.getX(), bottomRight.getY());
			topRight = Point2D(bottomRight.getX(), topLeft.getY());
		} else {
			topRight = pOne;
			bottomLeft = pTwo;
			bottomRight = Point2D(topRight.getX(), bottomLeft.getY());
			topLeft = Point2D(bottomLeft.getX(), topRight.getY());
		}
	}
}

// Copy Constructor
Rectangle::Rectangle(const Rectangle& rhs)
{
	width = rhs.width;
	height = rhs.height;
	bottomLeft = rhs.bottomLeft;
	bottomRight = rhs.bottomRight;
	topLeft = rhs.topLeft;
	topRight = rhs.topRight;
}

// Assignment operator
Rectangle& Rectangle::operator=(const Rectangle& rhs)
{
	if (this==&rhs)
	{
		width = rhs.width;
		height = rhs.height;
		bottomLeft = rhs.bottomLeft;
		bottomRight = rhs.bottomRight;
		topLeft = rhs.topLeft;
		topRight = rhs.topRight;
	}
	return *this;
}

bool Rectangle::operator== (const Rectangle& rhs)
{
	return width == rhs.width && height == rhs.height && bottomLeft == rhs.bottomLeft && bottomRight == rhs.bottomRight && topLeft == rhs.topLeft && topRight == rhs.topRight;
}

bool Rectangle::operator!= (const Rectangle& rhs)
{
	return !(this==&rhs);
}

// Method in the Class that allows you to check for collision between two axis-aligned Rectangles.
bool Rectangle::checkCollision(Rectangle& a)
{
	if ((checkCollision(a.bottomLeft) || checkCollision(a.bottomRight) ||checkCollision(a.topLeft) || checkCollision(a.topRight)) ||
		(a.checkCollision(this->bottomLeft) || a.checkCollision(this->bottomRight) ||a.checkCollision(this->topLeft) || a.checkCollision(this->topRight)))
	{
		return true;
	} else {
		return false;
	}
}

// Method for testing collision/intersection with a 2D point
bool Rectangle::checkCollision(Point2D& p)
{
	if ((bottomLeft.getX() <= p.getX() && bottomRight.getX() >= p.getX()) &&
		(bottomLeft.getY() <= p.getY() && topLeft.getY() >= p.getY()))
	{
		return true;
	} else {
		return false;
	}
}

// Method for printing the coordinates of the rectangle for testing purposes
void Rectangle::printCoordinates()
{
	cout << "(" <<  topLeft.getX() << ", " << topLeft.getY() << "), (" <<
					topRight.getX() << ", " << topRight.getY() << "), (" <<
					bottomRight.getX() << ", " << bottomRight.getY() << "), (" <<
					bottomLeft.getX() << ", " << bottomRight.getY() << ")" << endl;
}

// Simple test code that creates instances of your class and tests your implementation
void main()
{
	cout << "Testing constructing Rectangles using width, height, and an initial point." << endl;
	Rectangle rect1 = Rectangle(6.2,5.7,1.56,2.9);
	cout << "rect1 should be (1.56, 8.6), (7.76, 8.6), (7.76, 2.9), (1.56, 2.9)" << endl;
	cout << " rect1 results: ";
	rect1.printCoordinates();

	Rectangle rect2 = Rectangle(5,8,-8,-4);
	cout << "rect2 should be (-8, 4), (-3, 4), (-3, -4), (-8, -4)" << endl;
	cout << " rect2 results: ";
	rect2.printCoordinates();

	cout << "\nTesting constructing points and collision with rectangles." << endl;

	Point2D pGrey = Point2D(6.66,3.27);
	Point2D pYellow = Point2D(3.875,-3.4);
	Point2D pPink = Point2D(-5,7);
	Point2D pRed = Point2D(-7,3);

	cout << "Is pGrey colliding with rect1?" << endl;
	cout << "Expect: Yes	Result: ";
	if (rect1.checkCollision(pGrey))
	{
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}

	cout << "Is pYellow colliding with rect1?" << endl;
	cout << "Expect: No	Result: ";
	if (rect1.checkCollision(pYellow))
	{
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}

	cout << "Is pPink colliding with rect2?" << endl;
	cout << "Expect: No	Result: ";
	if (rect2.checkCollision(pPink))
	{
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}

	cout << "Is pRed colliding with rect2?" << endl;
	cout << "Expect: Yes	Result: ";
	if (rect2.checkCollision(pRed))
	{
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}

	cout << "\nTesting contructing rectangles using two points." << endl;
	Rectangle rect3 = Rectangle(pGrey,pYellow);
	cout << "rect3 should be (3.875, 3.27), (6.66, 3.27), (6.66, -3.4), (3.875, -3.4)" << endl;
	cout << " rect3 results: ";
	rect3.printCoordinates();

	Rectangle rect4 = Rectangle(pRed,pPink);
	cout << "rect4 should be (-7, 7), (-5, 7), (-5, 3), (-7, 3)" << endl;
	cout << " rect4 results: ";
	rect4.printCoordinates();

	cout << "\nTesting collision between two rectangles." << endl;

	cout << "Is rect1 colliding with rect2?" << endl;
	cout << "Expect: No	Result: ";
	if (rect1.checkCollision(rect2))
	{
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}

	cout << "Is rect2 colliding with rect4?" << endl;
	cout << "Expect: Yes	Result: ";
	if (rect2.checkCollision(rect4))
	{
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}

	cout << "Is rect4 colliding with rect2?" << endl;
	cout << "Expect: Yes	Result: ";
	if (rect4.checkCollision(rect2))
	{
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}

	cout << "Is rect3 colliding with rect1?" << endl;
	cout << "Expect: Yes	Result: ";
	if (rect3.checkCollision(rect1))
	{
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}

	cout << "Is rect1 colliding with rect3?" << endl;
	cout << "Expect: Yes	Result: ";
	if (rect1.checkCollision(rect3))
	{
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}

	cout << "Is rect4 colliding with rect3?" << endl;
	cout << "Expect: No	Result: ";
	if (rect4.checkCollision(rect3))
	{
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}

	cout << "\nTesting copy constructor." << endl;
	Rectangle rect5(rect1);
	cout << "Expect: (1.56, 8.6), (7.76, 8.6), (7.76, 2.9), (1.56, 2.9)" << endl;
	cout << "Result: ";
	rect5.printCoordinates();

	cout << "\nTesting assignment operator" << endl;
	Rectangle rect6 = rect2;
	cout << "Expect: (-8, 4), (-3, 4), (-3, -4), (-8, -4)" << endl;
	cout << "Result: ";
	rect6.printCoordinates();

	keep_window_open();
}