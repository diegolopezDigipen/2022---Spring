#include "Point4.h"             // Point4

Point4::Point4(void) : x(0),y(0),z(0), w(1) {}
// Copy constructor, copies every component from the other Point4
Point4::Point4(const Point4& rhs) : x(rhs.x), y(rhs.y), z(rhs.z), w(rhs.w) {}

// Non-Default constructor, self-explanatory
Point4::Point4(float xx, float yy, float zz, float ww) : x(xx), y(yy), z(zz), w(ww) {}

// Assignment operator, copies every component from the other Point4
Point4& Point4::operator=(const Point4& rhs)
{
	x = rhs.x;
	y = rhs.y;
	z = rhs.z;
	w = rhs.w;
	return *this;
}
// Unary negation operator, negates every component and returns a copy
Point4 Point4::operator-(void) const
{
	Point4 a;
	a.x = x * (-1.0f);
	a.y = y * (-1.0f);
	a.z = z * (-1.0f);
	a.w = w * (-1.0f);
	return a;
}
// Binary subtraction operator, Subtract two Point4s and you get a Vector4
Vector4 Point4::operator-(const Point4& rhs) const
{
	Vector4 a;
	a.x = x - rhs.x;
	a.y = y - rhs.y;
	a.z = z - rhs.z;
	a.w = w - rhs.w;
	return a;
}
// Basic vector math operations with points, you can add a Vector4 to a Point4, or
// subtract a Vector4 from a Point4
Point4 Point4::operator+ (const Vector4& rhs) const
{
	Point4 a;
	a.x = x + rhs.x;
	a.y = y + rhs.y;
	a.z = z + rhs.z;
	a.w = w + rhs.w;
	return a;
}

Point4 Point4::operator- (const Vector4& rhs) const
{
	Point4 a;
	a.x = x - rhs.x;
	a.y = y - rhs.y;
	a.z = z - rhs.z;
	a.w = w - rhs.w;
	return a;
}
// Same as previous two operators, just modifies the original instead of returning a
// copy
Point4& Point4::operator+=(const Vector4& rhs)
{
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	w += rhs.w;
	return *this;
}
Point4& Point4::operator-=(const Vector4& rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;
	w -= rhs.w;
	return *this;
}

// Comparison operators which should use an epsilon defined in
// MathUtilities.h to see if the value is within a certain range
// in which case we say they are equivalent.
bool Point4::operator==(const Point4& rhs) const
{
	if (x == rhs.x && y == rhs.y && z == rhs.z && w == rhs.w)
		return true;

	return false;
}
bool Point4::operator!=(const Point4& rhs) const
{
	if (*this == rhs)
		return false;

	return true;
}

// Sets x,y,z to zeroes, w to defined value
void Point4::Zero(void)
{
	x = 0;
	y = 0;
	z = 0;
	w = 1;
}