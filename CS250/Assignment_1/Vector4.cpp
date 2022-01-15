#include "Vector4.h"            // Vector4

#include "MathUtilities.h"
#include <cmath>

// Default constructor, initializes x,y,z to zeroes, w to defined value
Vector4::Vector4(void) : x(0), y(0), z(0), w(0) {}
// Copy constructor, copies every component from the other Vector4
Vector4::Vector4(const Vector4& rhs) : x(rhs.x), y(rhs.y), z(rhs.z), w(rhs.w) {}
// Non-Default constructor, self explanatory
Vector4::Vector4(float xx, float yy, float zz, float ww) : x(xx), y(yy), z(zz), w(ww) {}
// Assignment operator, does not need to handle self assignment
Vector4& Vector4::operator=(const Vector4& rhs)
{
	x = rhs.x;
	y = rhs.y;
	z = rhs.z;
	w = rhs.w;
	return *this;
}
// Unary negation operator, negates all components and returns a copy
Vector4 Vector4::operator-(void) const
{
	Vector4 a;
	a.x = x * (-1.0f);
	a.y = y * (-1.0f);
	a.z = z * (-1.0f);
	a.w = w * (-1.0f);
	return a;
}

// Basic Vector math operations. Add Vector to Vector B, or Subtract Vector A from
// Vector B, or multiply a vector with a scalar, or divide a vector by that scalar
Vector4 Vector4::operator+(const Vector4& rhs) const
{
	Vector4 a;
	a.x = x + rhs.x;
	a.y = y + rhs.y;
	a.z = z + rhs.z;
	a.w = w + rhs.w;
	return a;
}
Vector4 Vector4::operator-(const Vector4& rhs) const
{
	Vector4 a;
	a.x = x - rhs.x;
	a.y = y - rhs.y;
	a.z = z - rhs.z;
	a.w = w - rhs.w;
	return a;
}
Vector4 Vector4::operator*(const float rhs) const
{
	Vector4 a;
	a.x = x * rhs;
	a.y = y * rhs;
	a.z = z * rhs;
	a.w = w * rhs;
	return a;
}
Vector4 Vector4::operator/(const float rhs) const
{
	Vector4 a;
	a.x = x / rhs;
	a.y = y / rhs;
	a.z = z / rhs;
	a.w = w / rhs;
	return a;
}
// Same as above, just stores the result in the original vector
Vector4& Vector4::operator+=(const Vector4& rhs)
{
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	w += rhs.w;
	return *this;
}
Vector4& Vector4::operator-=(const Vector4& rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;
	w -= rhs.w;
	return *this;
}
Vector4& Vector4::operator*=(const float rhs)
{
	x *= rhs;
	y *= rhs;
	z *= rhs;
	w *= rhs;
	return *this;
}
Vector4& Vector4::operator/=(const float rhs)
{
	x /= rhs;
	y /= rhs;
	z /= rhs;
	w /= rhs;
	return *this;
}
// Comparison operators which should use an epsilon defined in
// MathUtilities.h to see if the value is within a certain range
// in which case we say they are equivalent.
bool Vector4::operator==(const Vector4& rhs) const
{
	if (x == rhs.x && y == rhs.y && z == rhs.z && w == rhs.w)
		return true;

	return false;
}
bool Vector4::operator!=(const Vector4& rhs) const
{
	if (*this == rhs)
		return false;

	return true;
}

// Computes the dot product with the other vector. Treat it as 3D vector.
float Vector4::Dot(const Vector4& rhs) const
{
	return x * rhs.x + y * rhs.y + z * rhs.z + w * rhs.w;
}
// Computes the cross product with the other vector. Treat it as a 3D vector.
Vector4 Vector4::Cross(const Vector4& rhs) const
{
	Vector4 crossP;
	crossP.v[0] = v[1] * rhs.v[2] - v[2] * rhs.v[1];
	crossP.v[1] = v[2] * rhs.v[0] - v[0] * rhs.v[2];
	crossP.v[2] = v[0] * rhs.v[1] - v[1] * rhs.v[0];
	return crossP;
}
// Computes the true length of the vector
float Vector4::Length(void) const
{
	return sqrt(x * x + y * y + z * z + w * w);
}
// Computes the squared length of the vector
float Vector4::LengthSq(void) const
{
	return x * x + y * y + z * z + w * w;
}

// Normalizes the vector to make the final vector be of length 1. If the length is zero
// then this function should not modify anything.
void Vector4::Normalize(void)
{
	float l = this->Length();
	if (l)
	{
		x /= l;
		y /= l;
		z /= l;
		w /= l;
	}
	else
	{
		x = 0;
		y = 0;
		z = 0;
		w = 0;
	}
}
// Sets x,y,z to zeroes, w to defined value
void Vector4::Zero(void)
{
	x = 0;
	y = 0;
	z = 0;
	w = 0;
}
