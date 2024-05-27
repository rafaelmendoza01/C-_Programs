// Matrix.h
// ELEC1204 Lab P4
// Enter the Matrix: Perceptron
// Ivan Ling  2024, MIT License
// Contributors: Ng Peng Hoo, Ivan Ling

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>

using namespace std;

class Matrix
{
private:
	vector<vector<double>> data;
	int row;
	int col;

public:
	Matrix();
	Matrix(vector<vector<double> > d);
	void print_matrix();
	Matrix operator+(Matrix &mat);
	Matrix operator-(Matrix &mat);
	Matrix operator*(Matrix &mat2);
	Matrix operator*(double num);
	vector<vector<double> > getdata();
	int getrow();
	int getcol();
};

#endif