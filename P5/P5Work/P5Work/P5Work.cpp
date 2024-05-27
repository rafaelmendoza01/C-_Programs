#include <cmath>
#include <iostream>
#include<array>
using namespace std;

class Gate {
    protected: 
        int output;
        int input1;
        int input2;
    public:
        int ReturnOutput() {
            return output;
        }
};

class ANDgate : public Gate {
    public:
        ANDgate(int inp1, int inp2) {
            input1 = inp1;
            input2 = inp2;
        }

        void CalcOutput() {
            if (input1 == 1 && input2 == 1) {
                output = 1;
            }
            else {
                output = 0;
            }
        }
        ~ANDgate() {
            input1 = NULL;
            input2 = NULL;
            output = NULL;
        }
};

class NOTgate : public Gate {
    public:
        NOTgate(int inp) {
            input1 = inp;
        }
        void calcOutput() {
            if (input1 == 1) {
                output = 0;
            }
            else {
                output = 1;
            }
        }
        ~NOTgate() {
            input1 = NULL;
            output = NULL;
        }
};

class ORgate : public Gate {
    public:
        ORgate(int inp1, int inp2) {
            input1 = inp1;
            input2 = inp2;
        }
        void CalcOutput() {
            if (input1 == 1 || input2 == 1) {
                output = 1;
            }
            else {
                output = 0;
            }
        }
        ~ORgate() {
            input1 = NULL;
            input2 = NULL;
            output = NULL;
        }
};

class XORgate : public Gate {
    public:
        XORgate(int inp1, int inp2) {
            input1 = inp1;
            input2 = inp2;
        }

        void CalcOutput() {
            if (input1 != input2) {
                output = 1;
            }
            else {
                output = 0;
            }
        }
        ~XORgate() {
            input1 = NULL;
            input2 = NULL;
            output = NULL;
        }
};

struct FullAdder {
    int Sum;
    int Cout;
};

FullAdder AdderCrcuit(int Bit1, int Bit2, int CIN) {
    FullAdder temp;
    int Sum;
    int Cout;

    XORgate xor1 = XORgate(Bit1, Bit2);
    xor1.CalcOutput();
    XORgate xor2 = XORgate(xor1.ReturnOutput(), CIN);
    xor2.CalcOutput();
    Sum = xor2.ReturnOutput();

    ANDgate and1 = ANDgate(Bit1, Bit2);
    ANDgate and2 = ANDgate(CIN, xor1.ReturnOutput());
    and1.CalcOutput(); and2.CalcOutput();
    ORgate orG = ORgate(and1.ReturnOutput(), and2.ReturnOutput());
    orG.CalcOutput();
    Cout = orG.ReturnOutput();

    temp.Cout = Cout;
    temp.Sum = Sum;
    return temp;
}

array<int, 8> twoscomplement(array<int, 8> Num) {
    array<int, 8> OppositeNumber;
    for (int i = 0; i < 8; i++) {
        if (Num[i] == 1) {
            OppositeNumber[i] = 0;
        }
        else {
            OppositeNumber[i] = 1;
        }
    }

    FullAdder temporary;
    int C = 1;
    for (int i = 7; i > 0; i--) {
        temporary = AdderCrcuit(OppositeNumber[i], 0, C);
        OppositeNumber[i] = temporary.Sum;
        C = temporary.Cout;
    }
    return OppositeNumber;
}

int main()
{
    //3.1 
    int A;
    int B;
    int Cin;
    cout << "Enter value for A ";
    cin >> A;
    cout << "Enter value for B ";
    cin >> B;
    cout << "Enter carry bit ";
    cin >> Cin;

    FullAdder Answer = AdderCrcuit(A, B, Cin);
    cout << "sum is " << Answer.Sum;
    cout << "\ncarry out is " << Answer.Cout;


    //3.2
    array<int, 8> Num1Bin = { 0,0,0,0,0,0,0,0 };
    array<int, 8> Num2Bin = { 0,0,0,0,0,0,0,0 };
    array<int, 8> SumBin = { 0,0,0,0,0,0,0,0 };

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
    for (int i = 0; i < 8; i++) {
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
    
    int CarryBit;
    CarryBit = TheirCarry;
    FullAdder ToAdd;
    for (int i = 7; i >= 0;i--) {
        ToAdd = AdderCrcuit(Num1Bin[i], Num2Bin[i], CarryBit);
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
                DecimalEquivalent += pow(2, exponent);
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



}


