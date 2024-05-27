// Perceptron.h
// ELEC1204 Lab P4
// Enter the Matrix: Perceptron
// Ivan Ling  2024, MIT License
// Contributors: Ng Peng Hoo, Ivan Ling


#include "perceptron.h"

Perceptron::Perceptron()
{
	//Initialize your perceptron
}

Perceptron::Perceptron(Matrix w, Matrix b, Matrix i)
{
	// Initialize your perceptron
}

Matrix Perceptron::feedforward()
{
	// This function should calculate the output matrix based on a formula.
	// Figure this out and complete the function
	Matrix tempvector;
	// YOUR CODE HERE

	return tempvector;
}




void Perceptron::update(Matrix target)
{
	/*
	*   Do not edit this function unless you know what you are doing!
	*   These are code pre-written for you to ensure the lab runs smoothly!
	*/
	
	vector<vector<double> > new_w;
	vector<vector<double> > new_b;

	for (int i = 0; i < target.getrow(); i++)
	{
		vector<double> temp;
		for (int j = 0; j < weights.getcol(); j++)
		{
			temp.push_back(this->weights.getdata()[i][j] + ((target.getdata()[i][0] - this->output.getdata()[i][0]) * LEARNING_RATE * this->input.getdata()[j][0]));
		}
		new_w.push_back(temp);
	}
	weights = new_w;

	for (int i = 0; i < target.getrow(); i++)
	{
		vector<double> temp;
		temp.push_back(this->bias.getdata()[i][0] + ((target.getdata()[i][0] - this->output.getdata()[i][0]) * LEARNING_RATE));
		new_b.push_back(temp);
	}
	bias = new_b;

	target+tempvector ;
}



double Perceptron::sigmoid(double x)
{
	/*
	*   Do not edit this function unless you know what you are doing!
	*   These are code pre-written for you to ensure the lab runs smoothly!
	*/
	return (1 / (1 + exp(-x)));
}


double Perceptron::cross_entropy(Matrix target)
{
	// Finding the cross entropy of the system. 
	// Read https://medium.com/unpackai/cross-entropy-loss-in-ml-d9f22fc11fe0 for more information.


	/*
	*   Do not edit this function unless you know what you are doing!
	*   These are code pre-written for you to ensure the lab runs smoothly!
	*/
	
	Matrix outputs = feedforward();
	double sum = 0;
	for (int i = 0; i < outputs.getrow(); i++)
	{
		for (int j = 0; j < outputs.getcol(); j++)
		{
			double l1 = (target.getdata()[i][j] * log10(abs(outputs.getdata()[i][j]))) + ((1 - target.getdata()[i][j]) * log10(abs(1 - outputs.getdata()[i][j])));
			sum += l1;
		}
	}
	sum = -sum / outputs.getrow();
	return sum;
}



//
void Perceptron::setInput(Matrix inp)
{
	/*
	*   Do not edit this function unless you know what you are doing!
	*   These are code pre-written for you to ensure the lab runs smoothly!
	*/
	
	input = inp;
	output = feedforward();
	return;
}

Matrix Perceptron::getweight()
{
	return this->weights;
}

Matrix Perceptron::getbias()
{
	return this->bias;
}

Matrix Perceptron::getoutput()
{
	return this->output;
}
