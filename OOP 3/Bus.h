#include <bits/stdc++.h>
using namespace std;
#include "car.h"
#include "truck.h"

class Bus : public Car, public Truck
{
public:
    Bus()
    {
        cout << "Bus constructor" << endl;
    }
    // void print()
    // {
    //     cout << "Bus" << endl;
    // }
};
