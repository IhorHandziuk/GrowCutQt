#ifndef MATRIX
#define MATRIX

#include<iostream>

template <typename U>
class Matrix
{
public:
	Matrix(int rows_, int columns_);
	Matrix();
	//Use this constructor with explicit type casting
	//e. g. ((int*)a, 3, 3);
	Matrix(U* source, int rows_, int columns_);
	Matrix(U** source, int rows_, int columns_);
	Matrix(const Matrix&);
	~Matrix();
	void setSize(int rows_, int columns_);
	void print() const;
	Matrix transposed() const;
	int rows() const;
	int columns() const;
	Matrix operator+(Matrix);
	Matrix operator*(Matrix);
	Matrix operator*(U);
	U* &operator[] (int i);
	U* &operator[] (int i) const;
	Matrix& operator =(Matrix);
	operator U** ();
	
protected:
	U** matrix;
	int Rows;
	int Columns;
};

template <typename U>
void Matrix<U>::print() const
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Columns; j++)
			std::cout << matrix[i][j] << " ";
		std:: cout << std::endl;
	}
	std::cout << std::endl;
}

template <typename U>
Matrix<U> Matrix<U>::transposed() const
{
	Matrix res(Columns, Rows);
	for (int i = 0; i < Rows; i++)
		for (int j = 0; j < Columns; j++) 
			res[j][i] = matrix[i][j];
	return res;
}

template<typename U>
inline int Matrix<U>::rows() const
{
	return Rows;
}

template<typename U>
int Matrix<U>::columns() const
{
	return Columns;
}

template <typename U>
Matrix<U>::Matrix(int rows_, int columns_) :
	Rows(rows_), Columns(columns_)
{
	matrix = new U*[Rows];
	for (int i = 0; i < Rows; i++)
		matrix[i] = new U[Columns];
}

template<typename U>
Matrix<U>::Matrix() :Rows(0), Columns(0){}

template <typename U>
Matrix<U>::Matrix(U* source, int rows_, int columns_)
{
	this->Rows = rows_;
	this->Columns = columns_;
	matrix = new U*[Rows];
	for (int i = 0; i < Rows; i++) {
		matrix[i] = new U[Columns];
		for (int j = 0; j < Columns; j++)
			matrix[i][j] = (*(source + i*Columns + j));
	}
}

template<typename U>
Matrix<U>::Matrix(U ** source, int rows_, int columns_)
{
	this->Rows = rows_;
	this->Columns = columns_;
	matrix = new U*[Rows];
	for (int i = 0; i < Rows; i++) {
		matrix[i] = new U[Columns];
		for (int j = 0; j < Columns; j++)
			matrix[i][j] = source[i][j];
	}
}

template<typename U>
Matrix<U>::Matrix(const Matrix &another)
{
	Rows = another.Rows;
	Columns = another.Columns;
	matrix = new U*[Rows];
	for (int i = 0; i < Rows; i++) {
		matrix[i] = new U[Columns];
		for (int j = 0; j < Columns; j++)
			matrix[i][j] = another.matrix[i][j];
	}
}

template<typename U>
Matrix<U>::~Matrix()
{
//	for (int i = 0; i < Rows; i++)
//		delete[] matrix[i];
//	if (Rows > 0)
//		delete[] matrix;
}

template<typename U>
inline void Matrix<U>::setSize(int rows_, int columns_)
{
	Rows = rows_;
	Columns = columns_;
	matrix = new U*[Rows];
	for (int i = 0; i < Rows; i++) {
		matrix[i] = new U[Columns];
	}
}

template <typename U>
Matrix<U> Matrix<U>::operator + (Matrix<U> A)
{
	if (A.Rows == Rows && A.Columns == Columns)
	{
		Matrix<U> C = A;
		for (int i = 0; i < A.Rows; i++)
			for (int j = 0; j < A.Columns; j++)
				C[i][j] = C[i][j] + matrix[i][j];
		return C;
	}
	else std::cerr << "Error: adding matrices with different dimensions";
}

template <typename U>
Matrix<U> Matrix<U>::operator * (Matrix<U> A)
{
	if (Columns == A.Rows)
	{
		Matrix<U> C(Rows, A.Columns);
		U data = 0.0;
		for (int i = 0; i < Rows; i++)
		{
			for (int j = 0; j < A.Columns; j++)
			{
				for (int r = 0; r < Columns; r++)
					data += matrix[i][r] * A[r][j];
				C[i][j] = data;
				data = 0;
			}
		}
		return C;
	}
	else std::cerr << "Error: multipling matrices whith inappropriate dimensions";
}

template <typename U>
Matrix<U> Matrix<U>::operator * (U alpha)
{
	Matrix<U> C = *this;
	for (int i = 0; i < Rows; i++)
		for (int j = 0; j < Columns; j++)
			C[i][j] *= alpha;
	return C;
}

template <typename U>
U* & Matrix<U>::operator[] (int i) {
	return matrix[i];
}

template <typename U>
U* & Matrix<U>::operator[] (int i) const{
	return matrix[i];
}

template<typename U>
Matrix<U> & Matrix<U>::operator=(Matrix<U> another)
{
	Rows = another.Rows;
	Columns = another.Columns;
	matrix = new U*[Rows];
	for (int i = 0; i < Rows; i++) {
		matrix[i] = new U[Columns];
		for (int j = 0; j < Columns; j++)
			matrix[i][j] = another[i][j];
	}
	return *this;
}

template<typename U>
inline Matrix<U>::operator U**()
{
	return matrix;
}

//template <typename T>
//class Vector : public Matrix<T>
//{
//public:
//	Vector(T ** source, int rows_) :
//		Matrix(source, rows_, 1) {}
//	Vector(T * source, int rows_) :
//		Matrix(source, rows_, 1) {}
//	Vector(int rows_) :
//		Matrix(rows_, 1) {}

//	T & operator[] (int i) {
//		return matrix[i][0];
//	}

//    operator Matrix() {
//    	return Matrix(matrix, rows, 1);
//    }
//};

#endif
