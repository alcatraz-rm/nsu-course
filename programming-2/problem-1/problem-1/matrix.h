#pragma once

#include <fstream>
using namespace std;


int** allocate_memory_for_matrix(size_t dim);

void copy_matrix(int** dest, int** source, size_t dim);

void delete_matrix(int** source, size_t dim);

class Matrix;

class Row {
	const size_t row_index;
	Matrix& matrix;

public:
	Row(size_t idx, Matrix& M);

	int& operator[](size_t idx);
};


class Column {
	const size_t column_index;
	Matrix& matrix;

public:
	Column(size_t idx, Matrix& M);

	int& operator[](size_t idx);
};


class Matrix {
	int** content;
	size_t dimension;

	friend class Row;
	friend class Column;

public:
	Matrix();

	Matrix(const size_t dim, int* diag_elements);

	// Initializing I here
	Matrix(const size_t dim);

	Matrix(const Matrix& that);

	Matrix(const size_t dim, ifstream& in);

	// matrix dimension getter
	size_t dim() const;

	Matrix& operator=(const Matrix& that);

	// matrix product
	Matrix operator*(const Matrix& that) const;

	Matrix operator*(const int constant) const;

	//matrix sum
	Matrix operator+(const Matrix& that) const;

	Matrix operator-(const Matrix& that) const;

	Matrix operator-();

	void operator+=(const Matrix& that);

	void operator-=(const Matrix& that);

	void operator*=(const Matrix& that);

	void operator*=(const int constant);

	//matrix equality
	bool operator==(const Matrix& that) const;

	bool operator!=(const Matrix& that) const;

	// transponse matrix
	Matrix operator~() const;

	Matrix operator()(size_t row, size_t column) const;

	Row operator[](const size_t index);

	Column operator()(const size_t index);

	void print() const;

	void print(ofstream& out) const;

	~Matrix();

};


Matrix operator*(int constant, const Matrix& A);
