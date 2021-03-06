#include "GVector.h"
#include <math.h>

GVector::GVector()
{
	x = y = z = 0;
}

GVector::GVector(float init)
{
	x = y = z = init;
}

GVector::GVector(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

GVector::GVector(const GVector& Other)
{
	this->x = Other.x;
	this->y = Other.y;
	this->z = Other.z;
}

void GVector::SetVector(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

void GVector::init(float init)
{
	x = y = z = init;
}

GVector GVector::StaticInit(float init)
{
	return GVector(init, init, init);
}

void GVector::ZeroOut()
{
	x = y = z = 0;
}

float GVector::Length() const
{
	return (float)sqrt(x*x + y*y + z*z);
}

GVector GVector::GetUnitVector()
{
	int mag = Length();
	return GVector(x / mag, y / mag, z / mag);
}

float GVector::GetAngle(const GVector& V1, const GVector& V2)
{
	return (float)acos( (V1 | V2) / (V1.Length() * V2.Length()) );
}

void GVector::AddFloatAmount(const float& AmountX, const float& AmountY, const float& AmountZ)
{
	this->x += AmountX;
	this->y += AmountY;
	this->z += AmountZ;
}

GVector& GVector::operator=(const GVector& other)
{
	this->x = other.x;
	this->y = other.y;
	this->z = other.z;
	return *this;
}

GVector& GVector::operator+=(const GVector& other)
{
	this->x += other.x;
	this->y += other.y;
	this->z += other.z;
	return *this;
}

GVector& GVector::operator-=(const GVector& other)
{
	this->x -= other.x;
	this->y -= other.y;
	this->z -= other.z;
	return *this;
}

GVector& GVector::operator*=(const float& scalar)
{
	this->x *= scalar;
	this->y *= scalar;
	this->z *= scalar;
	return *this;
}

GVector GVector::operator+(const GVector& other)
{
	GVector out(x + other.x, y + other.y, z + other.z);
	return out;
}

GVector GVector::operator-(const GVector& other)
{
	GVector out(x - other.x, y - other.y, z - other.z);
	return out;
}

float GVector::operator|(const GVector& other) const
{
	return x * other.x + y * other.y + z * other.z;
}

GVector GVector::operator*(const int& scalar)
{
	return GVector(x*scalar, y * scalar, z*scalar);
}

GVector GVector::operator*(const float& scalar)
{
	GVector	 out(x*scalar, y * scalar, z*scalar);
	return out;
}

GVector GVector::operator/(const float& scalar)
{
	GVector	 out(x/scalar, y / scalar, z/scalar);
	return out;
}

GVector GVector::operator*(const GVector& other)
{
	GVector out;
	out.x = this->y * other.z - this->z * other.y;
	out.y = this->z * other.x - this->x * other.z;
	out.z = this->x * other.y - this->y * other.x;

	return out;
}

bool GVector::operator==(const GVector& other)
{
	if (this->x == other.x &&
		this->y == other.y &&
		this->z == other.z)
		return true;

	return false;
}
