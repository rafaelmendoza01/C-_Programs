#include<array>
#include <iostream>
using namespace std;
#include <math.h>

struct FullAdder {
    int Sum;
    int Cout;
};

int AND_gate(int num1, int num2);
int OR_gate(int num1, int num2);
int XOR_gate(int num1, int num2);
FullAdder FullAdderCircuit(int num1, int num2, int cin);
std::array<int, 8> twoscomplement(array<int, 8> Num);

int main()
{
    //section 3.1
    int num1;
    int num2;
    int C;
    std::cout << "Enter your first binary number: ";
    cin >> num1;

    cout << "Enter your second binary number: ";
    cin >> num2;
    
    cout << "Enter your carry in number: ";
    cin >> C;

    FullAdder Answer;
    Answer = FullAdderCircuit(num1, num2, C);
    cout << "sum is " << Answer.Sum;
    cout << ". Carry out is " << Answer.Cout;



    //section 3.2 & 3.3
    int FirstNum;
    int SecondNum;
    char operation;
    int TheirCarry;

    cout << "\nEnter your first number ";
    cin >> FirstNum;

    cout << "Enter your second number ";
    cin >> SecondNum;

    cout << "Type either + or - for operation ";
    cin >> operation;

    cout << "Type your Carry in Bit";
    cin >> TheirCarry;

    array<int, 8> Num1Bin = { 0,0,0,0,0,0,0,0 };
    array<int, 8> Num2Bin = { 0,0,0,0,0,0,0,0 };
    
    array<int, 8> SumBin = { 0,0,0,0,0,0,0,0 };

    int temp1;
    int temp2;

    if (FirstNum < 0)
        temp1 = -FirstNum;
    else
        temp1 = FirstNum;

    if (SecondNum < 0)
        temp2 = -SecondNum;
    else
        temp2 = SecondNum;
    

    for (int i = 7; i > 0; i--) {
        Num1Bin[i] = temp1 % 2;
        Num2Bin[i] = temp2 % 2;

        temp1 /= 2;
        temp2 /= 2;
    }

    if (FirstNum < 0) {
        Num1Bin = twoscomplement(Num1Bin);
    }
    if (SecondNum < 0) {
        Num2Bin = twoscomplement(Num2Bin);
    }

    cout << "\nyour first number in binary is: ";
    for (int i = 0; i < 8; i++){
        cout << Num1Bin[i];
    }

    cout << "\nyour second number in binary is: ";
    for (int i = 0; i < 8; i++) {
        cout << Num2Bin[i];
    }

    cout << "\nyour expression is ";
    cout << FirstNum << operation << SecondNum;

    //Addition of the 8bit binary numbers;

    if (operation == '-') {
        Num2Bin = twoscomplement(Num2Bin);
    }
    int CarryBit = TheirCarry;
    FullAdder ToAdd;
    for (int i = 7; i >= 0; i--) {
        ToAdd = FullAdderCircuit(Num1Bin[i], Num2Bin[i], CarryBit);
        CarryBit = ToAdd.Cout;

        SumBin[i] = ToAdd.Sum;
    }

    cout << "\nResult is ";
    for (int i = 0; i < 8; i++) {
        cout << SumBin[i];
    }

    int exponent = 0;
    int DecimalEquivalent = 0;
    for (int i = 7; i >= 0; i--) {
        if (i == 0) {
            if (SumBin[0] == 1)
                DecimalEquivalent += -pow(2, exponent);
        }
        else {
            if (SumBin[i] == 1)
                DecimalEquivalent += pow(2,exponent);
        }
        exponent++;
    }
    cout << "\nNumber in denary is " << DecimalEquivalent;
    cout << "\nCarry: ";
    if (ToAdd.Cout == 1) {
        cout << "1";
    }
    else
        cout << "0";

    cout << "\nOverflow: ";
    if (num1 > 0 && num2 > 0 && DecimalEquivalent < 0)
        cout << "1";
    else if (num1 < 0 && num2 < 0 && DecimalEquivalent > 0)
        cout << "1";
    else
        cout << "0";

}

FullAdder FullAdderCircuit(int num1, int num2, int cin) {
    FullAdder temp;
    int Sum = XOR_gate(cin, XOR_gate(num1, num2));
    int Cout = OR_gate(AND_gate(num1, num2), AND_gate(cin, XOR_gate(num1, num2)));
    temp.Cout = Cout;
    temp.Sum = Sum;
    return temp;

}

std::array<int, 8> twoscomplement(array<int, 8> Num) {
    std::array<int, 8> OppositeNumber;

    for (int i = 0; i < 8; i++) {
        if (Num[i] == 1) {
            OppositeNumber[i] = 0;
        }
        else {
            OppositeNumber[i] = 1;
        }
    }

    FullAdder temporary;
    int CarryIn = 1;
    for (int i = 7; i > 0; i--) {
        temporary = FullAdderCircuit(OppositeNumber[i], 0, CarryIn);
        OppositeNumber[i] = temporary.Sum;
        CarryIn = temporary.Cout;

    }
    return OppositeNumber;

}

int AND_gate(int num1, int num2) {
    if (num1 == 1 && num2 == 1) 
        return 1;
    else
        return 0;
}
int OR_gate(int num1, int num2) {
    if (num1 == 1 || num2 == 1)
        return 1;
    else
        return 0;
}
int XOR_gate(int num1, int num2) {
    if (num1 != num2)
        return 1;
    else
        return 0;

}