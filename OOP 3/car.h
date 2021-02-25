#include <bits/stdc++.h>
using namespace std;
#include "inheritence.h"

class Car : virtual public Vehicle
{
public:
    int numGears;
    Car()
    {
        cout << "Car def constructor" << endl;
    }
    // Car(int x, int y) : Vehicle(x)
    // {
    //     cout << "Car's parametrized constructor" << endl;
    //     numGears = y;
    // }
    ~Car()
    {
        cout << "Car's destructor" << endl;
    }

    // void print()
    // {
    //     // cout << numTyres << endl;
    //     // cout << color << endl;
    //     // cout << numGears << endl;
    //     cout << "Car" << endl;
    // }
};