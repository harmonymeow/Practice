//Point2D.h
class Point2D
{
public:
	Point2D();
	Point2D(float a, float b);
	float getX() {return x;};
	float getY() {return y;};
	bool operator== (const Point2D& rhs);

private:
	float x;
	float y;
};