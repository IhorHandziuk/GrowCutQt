#ifndef TYPES
#define TYPES

#include <cmath>

class float3
{
public:
	//variables
	float x, y, z;

	//methods
	void normalize();
	float norm() const;
	float3 operator +(const float3& right) const;
	float3 operator -(const float3& right) const;

	float3(float _x, float _y, float _z);
	float3();
};

using uint = unsigned int;

#endif
