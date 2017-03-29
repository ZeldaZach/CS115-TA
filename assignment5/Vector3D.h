#ifndef Vector3D_3D_H
#define Vector3D_3D_H

#include <iostream>

class Vector3D
{
	private:
		float x;
		float y;
		float z;

	public:
		Vector3D();
		Vector3D(float x, float y, float z);
		Vector3D(const Vector3D* vec);
	
		Vector3D* operator+(const Vector3D &rhs);
		void operator+=(const Vector3D &rhs);
		Vector3D* operator-(const Vector3D &rhs);
		void operator-=(const Vector3D &rhs);
		Vector3D* operator*(float scalar);
		void operator*=(float scalar);
		Vector3D* operator/(float scalar);
		void operator/=(float scalar);
		bool operator==(const Vector3D &rhs);
		void operator=(const Vector3D &rhs);
		bool operator!=(const Vector3D &rhs);
		void operator-(); // Negate
		friend std::istream& operator>>(std::istream &is, Vector3D &rhs);
		friend std::ostream& operator<<(std::ostream &os, Vector3D &vec);
		
		float Magnitude();
		void Normalize();
		
		
};

#endif