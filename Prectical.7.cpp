#include <iostream>
using namespace std;

void add(int a, int b)
{
    cout << "Sum of " << a << "+" << b << " : " << a + b << "\n";
}

void add(double a, double b)
{
    cout << "Sum of " << a << "+" << b << " : " << a + b << "\n";
}

class Complex
{
    double real, imag;

public:
    Complex(double real = 0, double imag = 0)
    {
        this->real = real;
        this->imag = imag;
    }

    Complex operator+(const Complex &obj)
    {
        return Complex(real + obj.real, imag + obj.imag);
    }

    void display()
    {
        cout << real;
        if (imag >= 0)
        {
            cout << " + " << imag << "i";
        }
        else
        {
            cout << " - " << -imag << "i";
        }
        cout << "\n";
    }
};

int main()
{
    cout << "Student name: Ramesh Kumar\nURN: E25B001202\n\n";

    add(1, 2);
    add(3.5, 7.2);

    Complex a(1, -2.9);
    cout << "\nComplex number a: ";
    a.display();

    Complex b(3.1, 0.5);
    cout << "Complex number b: ";
    b.display();

    Complex c = a + b;
    cout << "Complex number c: ";
    c.display();

    return 0;
}
