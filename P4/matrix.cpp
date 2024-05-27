// Matrix.cpp
// ELEC1204 Lab P4
// Enter the Matrix: Perceptron
// Ivan Ling  2024, MIT License
// Contributors: Ng Peng Hoo, Ivan Ling


#include "matrix.h"

Matrix::Matrix()
{
    //let default matrix be identity matrix of 2x2
    row = 2;
    col = 2;
    data = { {1,0},{0,1} };
}
Matrix::Matrix(vector<vector<double>> input) : data(input)
{
    //YOUR CODE
}

void Matrix::print_matrix()
{
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (j == 0) {
                cout << "\n" << data[i][j] << " ";
            }
            else {
                cout << data[i][j];
            }
        }
    }
}


Matrix Matrix::operator+(Matrix &mat)
{
    if (mat.getcol() == col && mat.getrow() == row) {
        vector<vector<double>> result(row, vector<double>(col));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                result[i][j] = data[i][j] + mat[i][j];
            }
        }
    }
    else {
        cout << "Matrix dont have required dimensions to add";
    }
}
Matrix Matrix::operator-(Matrix &mat)
{
    
    if (mat.getcol() == col && mat.getrow() == row) {
        vector<vector<double>> result(row, vector<double>(col));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                result[i][j] = data[i][j] - mat[i][j];
            }
        }
        Matrix TheResult = Matrix(result);
        return TheResult;
    }
    else {
        cout << "Matrix dont have required dimensions to subtract";
        Matrix TheResult;
        return TheResult;
        
    }
}
Matrix Matrix::operator*(Matrix &mat2)
{
    //current matrix on LHS
    //mat2 on RHS
    if (col == mat2.getrow) {
        vector<vector<double>> result(row, vector<double>(mat2.getcol());
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < mat2.getcol(); j++) {
                for (int k = 0; k <= mat2.getrow(); k++) {
                    result[i][j] = result[i][j] + (data[i, k] * mat2[k, j]);
                }
            }
        }
    }
    else {
        cout << "Matrix dont have required dimensions to multiply";
        Matrix TheResult;
        return TheResult;

    }
}
Matrix Matrix::operator*(double num)
{
    vector<vector<double>> result(row, vector<double>(col));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            result[i][j] = num * data[i][j];
        }
    }
    Matrix TheResult = Matrix(result);
    return TheResult;
}

vector<vector<double> > Matrix::getdata()
{
    return this->data;
}

int Matrix::getrow()
{
    return this->row;
}
int Matrix::getcol()
{
    return this->col;
}
