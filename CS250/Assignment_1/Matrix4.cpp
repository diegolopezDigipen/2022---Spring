#include "Matrix4.h"            // Matrix4
#include "Vector4.h"            // Vector4
#include "MathUtilities.h"      // Math functions
#include <cmath>

#define CELLS 16
#define SIZE   4

// Default constructor should initialize to zeroes
Matrix4::Matrix4(void) : v{} {}

// Copy constructor, copies every entry from the other matrix.
Matrix4::Matrix4(const Matrix4& rhs)
{
    for (unsigned i = 0u; i < CELLS; i++)
    {
        v[i] = rhs.v[i];
    }
}

// Non-default constructor, self-explanatory
Matrix4::Matrix4(float mm00, float mm01, float mm02, float mm03,
    float mm10, float mm11, float mm12, float mm13,
    float mm20, float mm21, float mm22, float mm23,
    float mm30, float mm31, float mm32, float mm33) : v{ mm00, mm01, mm02, mm03,
                                                         mm10, mm11, mm12, mm13,
                                                         mm20, mm21, mm22, mm23,
                                                         mm30, mm31, mm32, mm33 } {}

// Assignment operator, does not need to handle self-assignment
Matrix4& Matrix4::operator=(const Matrix4& rhs)
{
    for (unsigned i = 0u; i < CELLS; i++)
    {
        v[i] = rhs.v[i];
    }
    return *this;
}

// Multiplying a Matrix4 with a Vector4 or a Point4
Vector4 Matrix4::operator*(const Vector4& rhs) const
{
    Vector4 MultiplyVec;
    for (int i = 0; i < SIZE; i++)
    {
        MultiplyVec.v[i] = v[i*SIZE] * rhs.v[0] + v[i * SIZE+ 1] * rhs.v[1] + v[i * SIZE +2] * rhs.v[2] + v[i * SIZE+3] * rhs.v[3];
    }
    return MultiplyVec;
}
Point4 Matrix4::operator*(const Point4& rhs) const
{
    Point4 MultiplyPt;
    for (int i = 0; i < SIZE; i++)
    {
        MultiplyPt.v[i] = v[i * SIZE] * rhs.v[0] + v[i * SIZE + 1] * rhs.v[1] + v[i * SIZE + 2] * rhs.v[2] + v[i * SIZE + 3] * rhs.v[3];
    }
    return MultiplyPt;
}

// Basic Matrix arithmetic operations
Matrix4 Matrix4::operator+(const Matrix4& rhs) const
{
    Matrix4 Sum;
    for (unsigned i = 0u; i < CELLS; i++)
    {
        Sum.v[i] = v[i] + rhs.v[i];
    }
    return Sum;
}
Matrix4 Matrix4::operator-(const Matrix4& rhs) const
{
    Matrix4 Rest;
    for (unsigned i = 0u; i < CELLS; i++)
    {
        Rest.v[i] = v[i] - rhs.v[i];
    }
    return Rest;
}
Matrix4 Matrix4::operator*(const Matrix4& rhs) const
{
    Matrix4 Multiply = *this;
    Multiply *= rhs;
    return Multiply;
}

// Similar to the three above except they modify the original
Matrix4& Matrix4::operator+=(const Matrix4& rhs)
{
    for (unsigned i = 0u; i < CELLS; i++)
    {
        v[i] += rhs.v[i];
    }
    return *this;
}
Matrix4& Matrix4::operator-=(const Matrix4& rhs)
{
    for (unsigned i = 0u; i < CELLS; i++)
    {
        v[i] -= rhs.v[i];
    }
    return *this;
}
Matrix4& Matrix4::operator*=(const Matrix4& rhs)
{
    //New Matrix to store the data while calculating
    Matrix4 res;

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            float result = 0;
            for (int k = 0; k < SIZE; k++)
            {
                result += m[i][k] * rhs.m[k][j];
            }
            res.m[i][j] = result;
        }
    }

    *this = res;

    return *this;
}

// Scale/Divide the entire matrix by a float
Matrix4 Matrix4::operator*(const float rhs) const
{
    Matrix4 Scale;
    for (unsigned i = 0u; i < CELLS; i++)
    {
        Scale.v[i] = v[i] * rhs;
    }
    return Scale;
}
Matrix4 Matrix4::operator/(const float rhs) const
{
    Matrix4 Scale;
    for (unsigned i = 0u; i < CELLS; i++)
    {
        Scale.v[i] = v[i] / rhs;
    }
    return Scale;
}
// Same as previous
Matrix4& Matrix4::operator*=(const float rhs)
{   
    for (unsigned i = 0u; i < CELLS; i++)
    {
        v[i] *= rhs;
    }
    return *this;
}
Matrix4& Matrix4::operator/=(const float rhs)
{
    for (unsigned i = 0u; i < CELLS; i++)
    {
        v[i] /= rhs;
    }
    return *this;
}

// Comparison operators which should use an epsilon defined in
// MathUtilities.h to see if the value is within a certain range
// in which case we say they are equivalent.
bool Matrix4::operator==(const Matrix4& rhs) const
{
    for (unsigned i = 0u; i < CELLS; i++)
    {
        if (v[i] != rhs.v[i])
            return false;
    }
    return true;
}
bool Matrix4::operator!=(const Matrix4& rhs) const
{
    if (*this == rhs)
        return false;
    else
        return true;
}

// Zeroes out the entire matrix
void Matrix4::Zero(void)
{
    for (unsigned i = 0u; i < CELLS; i++)
    {
        v[i] = 0;
    }
}

// Builds the identity matrix
void Matrix4::Identity(void)
{
    this->Zero();
    this->v[0] = 1;
    this->v[5] = 1;
    this->v[10] = 1;
    this->v[15] = 1;
}