#include <bits/stdc++.h>
using namespace std;
#include "car.h"
#include "truck.h"

class Bus : public Car, public Truck
{
public:
    Bus() : Vehicle(5)
    {
        cout << "Bus constructor" << endl;
    }
    // void print()
    // {
    //     cout << "Bus" << endl;
    // }
};
