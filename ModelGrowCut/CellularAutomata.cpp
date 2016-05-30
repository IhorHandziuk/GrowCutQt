#include "CellularAutomata.h"
#include <algorithm>

CellularAutomata::CellularAutomata(const Matrix<float3>& source) 
{
	setField(source);
}

Matrix<Cell> CellularAutomata::getField() const
{
	return field;
}

Cell CellularAutomata::getCell(int i, int j) const
{
	return field[i][j];
}

vector<Cell> CellularAutomata::getNeighbors(int i, int j) const
{
    vector<Cell> res;
    if ((i != 0) && (field[i - 1][j].strength > 0))
        res.push_back(field[i - 1][j]);
    if ((j != 0) && (field[i][j - 1].strength > 0))
        res.push_back(field[i][j - 1]);
    if ((i < (field.rows() - 1)) && (field[i + 1][j].strength > 0))
        res.push_back(field[i + 1][j]);
    if ((j < (field.columns() - 1)) && (field[i][j + 1].strength > 0))
        res.push_back(field[i][j + 1]);


    if ((i != 0) && (j != 0) && (field[i - 1][j - 1].strength > 0))
        res.push_back(field[i - 1][j - 1]);

    if ((i != 0) && (j < (field.columns() - 1)) && (field[i - 1][j + 1].strength > 0))
        res.push_back(field[i - 1][j + 1]);

    if ((i < (field.rows() - 1)) && (j != 0) && (field[i + 1][j - 1].strength > 0))
        res.push_back(field[i + 1][j - 1]);

    if ((i < (field.rows() - 1)) && (j < (field.columns() - 1)) && (field[i + 1][j + 1].strength > 0))
        res.push_back(field[i + 1][j + 1]);
    return res;
}


void CellularAutomata::setField(const Matrix<float3>& source)
{
	field.setSize(source.rows(), source.columns());
    rowsInd.resize(source.rows());
    columnsInd.resize(source.columns());
    for (int i = 0; i < source.rows(); i++)
	{
        rowsInd[i] = i;
        for (int j = 0; j < source.columns(); j++)
		{
			field[i][j].color = source[i][j];
            if (i == 0)
            {
                columnsInd[j] = j;
            }
		}
	}
    random_shuffle ( rowsInd.begin(), rowsInd.end() );
    random_shuffle ( columnsInd.begin(), columnsInd.end() );
}

void CellularAutomata::setCell(int i, int j, Label lb, float strength)
{
    if ((i >= 0)&&(j >= 0)&&(i < field.rows())&&(j < field.columns()))
    {
        field[i][j].label = lb;
        field[i][j].strength = strength;
    }
}

float CellularAutomata::g(float x) const {
    return 1 - x / 441.673f; //441.673 = sqrt(255*255 * 3)
}

void CellularAutomata::iterate()
{ 
    for (int i = 0; i < field.rows(); i++)
	{
        for (int j = 0; j < field.columns(); j++)
		{
            for (auto q : getNeighbors(rowsInd[i], columnsInd[j]))
			{
                float attackStrength = g((field[rowsInd[i]][columnsInd[j]].color - q.color).norm()) * q.strength;
                if (attackStrength > field[rowsInd[i]][columnsInd[j]].strength)
				{
                    field[rowsInd[i]][columnsInd[j]].label = q.label;
                    field[rowsInd[i]][columnsInd[j]].strength = attackStrength;
				}
			}
		}
	}
}
