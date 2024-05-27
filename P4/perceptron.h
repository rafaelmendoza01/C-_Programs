// Perceptron.h
// ELEC1204 Lab P4
// Enter the Matrix: Perceptron
// Ivan Ling  2024, MIT License
// Contributors: Ng Peng Hoo, Ivan Ling

#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include <iostream>
#include <cmath>
#include "matrix.h"
#include "matrix.cpp"
#define LEARNING_RATE 0.001

class Perceptron
{
private:
	Matrix weights;
	Matrix bias; 
	Matrix input;
	Matrix output;

public:
	Perceptron();
	Perceptron(Matrix w, Matrix b, Matrix i);
	Matrix feedforward();
	void update(Matrix target);
	double sigmoid(double value);		 
	double cross_entropy(Matrix target); 
	Matrix getweight();
	Matrix getbias();
	Matrix getoutput();
	void setInput(Matrix i);
};

#endif