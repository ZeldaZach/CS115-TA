#include "Vector3D.h"
#include <cmath>
#include <iostream>

Vector3D::Vector3D() : x(0), y(0), z(0)
{
}

Vector3D::Vector3D(float a, float b, float c) : x(a), y(b), z(c)
{
}

Vector3D::Vector3D(const Vector3D* vec) : x(vec->x), y(vec->y), z(vec->z)
{
}

Vector3D* Vector3D::operator+(const Vector3D &rhs)
{
	float n_x = this->x + rhs.x;
	float n_y = this->y + rhs.y;
	float n_z = this->z + rhs.z;

	Vector3D *tmp = new Vector3D(n_x, n_y, n_z);
	return tmp;
}

void Vector3D::operator+=(const Vector3D &rhs)
{
	this->x += rhs.x;
	this->y += rhs.y;
	this->z += rhs.z;
}

Vector3D* Vector3D::operator-(const Vector3D &rhs)
{
	float n_x = this->x - rhs.x;
	float n_y = this->y - rhs.y;
	float n_z = this->z - rhs.z;

	Vector3D *tmp = new Vector3D(n_x, n_y, n_z);
	return tmp;
}

void Vector3D::operator-=(const Vector3D &rhs)
{
	this->x -= rhs.x;
	this->y -= rhs.y;
	this->z -= rhs.z;
}

Vector3D* Vector3D::operator*(float scalar)
{
	float n_x = this->x * scalar;
	float n_y = this->y * scalar;
	float n_z = this->z * scalar;

	Vector3D *tmp = new Vector3D(n_x, n_y, n_z);
	return tmp;
}

void Vector3D::operator*=(float scalar)
{
	this->x = this->x * scalar;
	this->y = this->y * scalar;
	this->z = this->z * scalar;
}

Vector3D* Vector3D::operator/(float scalar)
{
	float n_x = this->x / scalar;
	float n_y = this->y / scalar;
	float n_z = this->z / scalar;

	Vector3D *tmp = new Vector3D(n_x, n_y, n_z);
	return tmp;
}

void Vector3D::operator/=(float scalar)
{
	this->x = this->x / scalar;
	this->y = this->y / scalar;
	this->z = this->z / scalar;
}

bool Vector3D::operator==(const Vector3D &rhs)
{
	return (this->x == rhs.x && this->y == rhs.y && this->z == rhs.z);
}

void Vector3D::operator=(const Vector3D &rhs)
{
	this->x = rhs.x;
	this->y = rhs.y;
	this->z = rhs.z;
}

bool Vector3D::operator!=(const Vector3D &rhs)
{
	return (*this == rhs ? false : true);
}

void Vector3D::operator-() // Negate
{
	this->x = -this->x;
	this->y = -this->y;
	this->z = -this->z;
}

std::istream& operator>>(std::istream &is, Vector3D &rhs)
{
	is >> rhs.x >> rhs.y >> rhs.z;
	return is;
}

std::ostream& operator<<(std::ostream &os, Vector3D &vec)
{
	os << vec.x << " " << vec.y << " " << vec.z;
	return os;
}

float Vector3D::Magnitude()
{
	// sqrt(x^2 + y^2 + z^2)
	return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
}

void Vector3D::Normalize()
{
	float length = Magnitude();
	
	if (length == 0)
		return;

	*this /= length;
}