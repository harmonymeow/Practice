//Rectangle.h
/* Specification:
		Design and Implement a C++ program that implements the following:
			- 2D Rectangle Class with floating point coordinates.
			- Methods for constructing a Rectangle with initial size and coordinates
			- Copy and Assignment constructors/operators
			- Method in the Class that allows you to check for collision between two axis-aligned Rectangles.
			- Method for testing collision/intersection with a 2D point
			- Simple test code that creates instances of your class and tests your implementation
*/
#include "Point2D.h"

// 2D Rectangle Class with floating point coordinates.
class Rectangle
{
public:
	// Methods for constructing a Rectangle with initial size and coordinates
	Rectangle(float Width, float Height, float X, float Y);
	Rectangle(Point2D& pOne, Point2D& pTwo);

	// Copy Constructor
	Rectangle(const Rectangle& copy);

	// Assignment operator
	Rectangle& operator=(const Rectangle& rhs);
	
	// Method in the Class that allows you to check for collision between two axis-aligned Rectangles.
	bool checkCollision(Rectangle& a);

	// Method for testing collision/intersection with a 2D point
	bool checkCollision(Point2D&);

	// Method for printing the coordinates of the rectangle for testing purposes
	void printCoordinates();

	// Overloaded operators
	bool operator== (const Rectangle& rhs);
	bool operator!= (const Rectangle& rhs);

private:
	// Size of the rectangle
	float width;
	float height;
	// The coordinates of the rectangle
	Point2D bottomLeft;
	Point2D bottomRight;
	Point2D topLeft;
	Point2D topRight;
};