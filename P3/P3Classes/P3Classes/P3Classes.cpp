#include <iostream>
#include <cmath>
using namespace std;
class ComplexNumber {
    private:
        double RealPart;
        double ImaginaryPart;
    public:
        void PrintNumber();
        double Re();
        double Im();
        double Mod();
        double Phase();
        ComplexNumber(double Real, double Imaginary) {
            RealPart = Real;
            ImaginaryPart = Imaginary;
        }
        ComplexNumber() {
            RealPart = 0;
            ImaginaryPart = 0;
        }
 
};

ComplexNumber operator+(ComplexNumber Complex1, ComplexNumber Complex2);
ComplexNumber operator-(ComplexNumber Complex1, ComplexNumber Complex2);
ComplexNumber operator*(ComplexNumber Complex1, ComplexNumber Complex2);
ComplexNumber operator/(ComplexNumber Complex1, ComplexNumber Complex2);

class RLC_circuit {
    private:
        double w, VoltAmpl, c, l, r;
        double const VoltagePhase = 0;
        ComplexNumber Impedance;
        ComplexNumber Voltage;
        ComplexNumber Current;
        double phaseDifference; //difference between current and voltage

    public:
        RLC_circuit(double w_in, double VoltAmpl_in, double c_in, double l_in, double r_in) {
            w = w_in;
            VoltAmpl = VoltAmpl_in;
            c = c_in;
            l = l_in;
            r = r_in;
            Impedance = ComplexNumber(r, (w * l) - (1.0 / (w * c)));
            Voltage = ComplexNumber(VoltAmpl * cos(w + VoltagePhase), VoltAmpl * sin(w + VoltagePhase));
            phaseDifference = Voltage.Phase() - Impedance.Phase();
            
        }
        ComplexNumber CurrentInCircuit() {
            Current = ComplexNumber((VoltAmpl / Impedance.Mod()) * cos(phaseDifference),
                (VoltAmpl / Impedance.Mod()) * sin(phaseDifference));
            return Current;
        }   
        void DisplayCurrent();
        void PhaseDifference();
};

int main()
{


    //section 3.1
    ComplexNumber const RandomComplex = ComplexNumber(3, 4);
    double TheirReal;
    double TheirImaginary;
    std::cout << "Enter Real Part of Complex Num: ";
    cin >> TheirReal;
    cout << "\nEnter Imaginary Part of Complex Num: ";
    cin >> TheirImaginary;
    ComplexNumber TheirComplexNum = ComplexNumber(TheirReal, TheirImaginary);

    cout << "\n Modulus: " << TheirComplexNum.Mod();
    cout << "\n Phase: " << TheirComplexNum.Phase() << " radians";
    cout << "\n Your Number is ";
    TheirComplexNum.PrintNumber();

    ComplexNumber Temp = TheirComplexNum + RandomComplex;
    Temp.PrintNumber();
    Temp = TheirComplexNum - RandomComplex;
    Temp.PrintNumber();
    Temp = TheirComplexNum * RandomComplex;
    Temp.PrintNumber();
    Temp = TheirComplexNum / RandomComplex;
    Temp.PrintNumber();

    //3.2 & 3.3
    double R; //resistance
    double W; //omega
    double C; //capacitance
    double L; //inductance
    double VoltagePhase;
    double VoltageAmplitude;

    cout << "\nEnter your resistance: ";
    cin >> R;
    cout << "\nEnter your omega: ";
    cin >> W;
    cout << "\nEnter your capacitance: ";
    cin >> C;
    cout << "\nEnter your inductance: ";
    cin >> L;
    cout << "\nEnter your Voltage amplitude: ";
    cin >> VoltageAmplitude;
    RLC_circuit TheirCircuit = RLC_circuit(W, VoltageAmplitude, C, L, R);
    TheirCircuit.CurrentInCircuit();
    TheirCircuit.DisplayCurrent();
    TheirCircuit.PhaseDifference();

};

double ComplexNumber::Re() {
    return RealPart;
};

double ComplexNumber::Im() {
    return ImaginaryPart;
};

void ComplexNumber::PrintNumber() {
    if (RealPart > 0 && ImaginaryPart > 0) {
        cout << RealPart << "+j" << ImaginaryPart << "\n";
    }
    else if (RealPart < 0 && ImaginaryPart > 0) {
        cout << RealPart << "+j" << ImaginaryPart << "\n";
    }
    else if (RealPart > 0 && ImaginaryPart < 0) {
        cout << RealPart << "-j" << -ImaginaryPart << "\n";
    }
    else if(RealPart < 0 && ImaginaryPart < 0) {
        cout << RealPart << "-j" << -ImaginaryPart << "\n";
    }
    else {
        cout << "0 + 0j";
    }

};

double ComplexNumber::Mod() {
    double Modulus;
    Modulus = sqrt(pow(RealPart, 2.0) + pow(ImaginaryPart, 2.0));
    return Modulus;
};

double ComplexNumber::Phase() {
    double angle = atan(ImaginaryPart / RealPart);
    return angle;
};

void RLC_circuit::DisplayCurrent() {
    cout << "\ncurrent is " << Current.Re() << " +j" << Current.Im() << "\n";
}

void RLC_circuit::PhaseDifference() {
    cout << "\n Phase difference between current and voltage is " << phaseDifference;
}

ComplexNumber operator+(ComplexNumber Complex1, ComplexNumber Complex2) {
    double Real = Complex1.Re() + Complex2.Re();
    double Imaginary = Complex1.Im() + Complex2.Im();
    return ComplexNumber(Real, Imaginary);
}

ComplexNumber operator-(ComplexNumber Complex1, ComplexNumber Complex2) {
    double Real = Complex1.Re() - Complex2.Re();
    double Imaginary = Complex1.Im() - Complex2.Im();
    return ComplexNumber(Real, Imaginary);
}

ComplexNumber operator*(ComplexNumber Complex1, ComplexNumber Complex2) {
    double Real = (Complex1.Re() * Complex2.Re()) - (Complex1.Im() * Complex2.Im());
    double Imaginary = (Complex1.Re() * Complex2.Im()) + (Complex1.Im() * Complex2.Re());
    return ComplexNumber(Real, Imaginary);

}
ComplexNumber operator/(ComplexNumber Complex1, ComplexNumber Complex2) {
    double Real = (Complex1.Re() * Complex2.Re() + Complex1.Im() * Complex2.Im())/(pow(Complex2.Im(), 2) + pow(Complex2.Re(),2));
    double Imaginary = (-Complex1.Re() * Complex2.Im() + Complex1.Im() * Complex2.Re()) / (pow(Complex2.Im(), 2) + pow(Complex2.Re(), 2));
    return ComplexNumber(Real, Imaginary);

}