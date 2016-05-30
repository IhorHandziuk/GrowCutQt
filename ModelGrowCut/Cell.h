#ifndef CELL
#define CELL

#include "BasicTypes.h"

enum Label { background, object };

struct Cell
{
	Label label;
	float strength;
	float3 color;

	Cell(float3 _color)
		:
		color(_color),
		label(background),
		strength(0.0f)
	{}

	Cell()
		:
		color(0.0f, 0.0f, 0.0f),
		label(background),
		strength(0.0f)
	{}
};

#endif

