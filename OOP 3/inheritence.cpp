#include <bits/stdc++.h>
using namespace std;

class Vehicle
{
private:
    int maxSpeed;

protected:
    int numTyres;

public:
    string color;

    /* Vehicle()
    {
        cout << "Vehicle's default constructor" << endl;
    }

    */
    Vehicle(int z)
    {
        cout << "Vehicle Parametrized constructor" << endl;
        maxSpeed = z;
    }

    ~Vehicle()
    {
        cout << "Vehicle's destructor" << endl;
    }
};
