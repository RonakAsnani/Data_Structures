#include <bits/stdc++.h>
using namespace std;
#include "inheritence.cpp"

class Car : public Vehicle
{
public:
    int numGears;
    Car(int x, int y) : Vehicle(x)
    {
        cout << "Car's parametrized constructor" << endl;
        numGears = y;
    }
    ~Car()
    {
        cout << "Car's destructor" << endl;
    }

    void print()
    {
        cout << numTyres << endl;
        cout << color << endl;
        cout << numGears << endl;
    }
};