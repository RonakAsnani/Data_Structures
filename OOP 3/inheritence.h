#include <bits/stdc++.h>
using namespace std;
#ifndef INHERITENCE_H
#define INHERITENCE_H

class Vehicle
{
private:
    int maxSpeed;

protected:
    int numTyres;

public:
    string color;

    // Vehicle()
    // {
    //     cout << "Vehicle's default constructor" << endl;
    // }

    Vehicle(int z)
    {
        cout << "Vehicle Parametrized constructor"
             << " " << z << endl;
        maxSpeed = z;
    }

    ~Vehicle()
    {
        cout << "Vehicle's destructor" << endl;
    }
    void print()
    {
        cout << "Vehicle" << endl;
    }
};
#endif
