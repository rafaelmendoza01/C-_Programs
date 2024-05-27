#include "perceptron.h"
#include "perceptron.cpp"
#include <vector>
int main()
{

    //Initialize your input vector to a vector of your choice
    // E.g.  vector<vector<double> > input_vector = {};
    // YOUR CODE HERE


    //Converts your vector to a Matrix Object
    Matrix input(vector<vector<double>>input_vector);


    //Initialize a target vector of your choice, an example is given
    // E.g. vector<vector<double> > target_v = {{1.0},{0},{0},{1.0}}; 
    // YOUR CODE HERE

    //Converts your vector to a Matrix Object
    Matrix target(vector<vector<double>>target_v);


    //Initialize your weight_vector and bias_vector with random values

    //HINT: Weight vector's dimension is input_size X output_size
    //  Weight vector example: vector<vector<double>> weight_vector;
    //  Bias vector example: vector<vector<double>> bias_vector;
    // YOUR CODE HERE



    //Creates Matrix object for those vectors
    Matrix weights(vector<vector<double>>weight_vector);
    Matrix bias(vector<vector<double>>bias_vector);


    //Initializes a perceptron with your weights, bias and input
    Perceptron p1(weights, bias, input);

    //Prints initial Value
    cout << "--------------------------------------------" << endl;
    cout << "Initial weights: " << endl;
    weights.print_matrix();
    cout << "--------------------------------------------" << endl;
    cout << "Initial bias: " << endl;
    bias.print_matrix();
    cout << "--------------------------------------------" << endl;


    // Calculate the output of the un-trained network using your current input
    Matrix output = p1.feedforward();

    //Prints the output
    cout << "Output: " << endl;
    output.print_matrix();
    cout << "--------------------------------------------" << endl;

    //Calculates the losses between current output with the target
    double losses = p1.cross_entropy(target);
    cout << "Current cross_entropy: " << losses << endl;

    //Set losses back to 1 and begin training
    losses = 1;

    //Set epoch counter
    int i = 0;

    system("pause");

    while (losses > 0.001) //Feel free to change the target accuracy
    {
        p1.feedforward(); //Run a feed forward with current input
        losses = p1.cross_entropy(target); // Check losses
        p1.update(target); //Update weights
        cout << "EPOCH " << i << ", cross_entropy = " << losses << endl;
        i++;
    }

    cout << "Final weights: " << endl;
    weight = p1.getweight();
    weight.print_matrix();
    cout << "--------------------------------------------" << endl;

    cout << "Final bias: " << endl;
    bias = p1.getbias();
    bias.print_matrix();
    cout << "--------------------------------------------" << endl;

    cout << "Final output: " << endl;
    output = p1.feedforward();
    output.print_matrix();
    cout << "--------------------------------------------" << endl;
    

    Matrix matrix;
    matrix.print_matrix();

    return 0;
}
