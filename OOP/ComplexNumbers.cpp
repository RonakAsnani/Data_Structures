#include <bits/stdc++.h>
using namespace std;

class ComplexNumbers
{
private:
    int real;
    int ima;

public:
    ComplexNumbers(int real, int ima)
    {
        this->real = real;
        this->ima = ima;
    }

    void plus(ComplexNumbers const &c2)
    {
        real = real + c2.real;
        ima = ima + c2.ima;
    }
    void multiply(ComplexNumbers const &c2)
    {
        real = real * c2.real + ((-1) * ima * c2.ima);
        ima = ima * c2.real + real * c2.ima;
    }
    void print()
    {
        cout << real << " " << ima << endl;
    }
};