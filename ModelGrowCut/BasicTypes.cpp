#include "BasicTypes.h"

float3::float3(float _x, float _y, float _z) 
	: x(_x), y(_y), z(_z) {}


float3::float3() 
	: x(0), y(0), z(0) {}

void float3::normalize()
{
	float norm = std::sqrt(x*x + y*y + z*z);
	x /= norm;
	y /= norm;
	z /= norm;
}

float float3::norm() const {
	return sqrt(x*x + y*y + z*z);
}

float3 float3::operator+(const float3 & right) const
{

	return float3(x + right.x,
				  y + right.y,
			      z + right.z);
}

float3 float3::operator-(const float3 & right) const
{
	return float3(x - right.x,
				  y - right.y,
				  z - right.z);
}
