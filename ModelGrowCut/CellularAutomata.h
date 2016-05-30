#ifndef CELLULAR
#define CELLULAR

#include <vector>
#include "Matrix.h"
#include "BasicTypes.h"
#include "Cell.h"

using std::vector;

class CellularAutomata 
{
public:
	CellularAutomata(const Matrix<float3>& source);
	CellularAutomata() {}

	Matrix<Cell> getField() const;
	Cell getCell(int i, int j) const;
	vector<Cell> getNeighbors(int i, int j) const;

	void setField(const Matrix<float3>& source);
	void setCell(int i, int j, Label lb, float force);
	//monotonous decreasing function bounded to [0,1]
	float g(float x) const;
	void iterate();
private:
	Matrix<Cell> field;
    vector<int> rowsInd;
    vector<int> columnsInd;
};

#endif
