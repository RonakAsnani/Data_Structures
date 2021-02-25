#include <bits/stdc++.h>
using namespace std;
#include "inheritence.h"

class Truck : virtual public Vehicle
{
public:
    Truck()
    {
        cout << "Truck constructor" << endl;
    }
    // void print()
    // {
    //     cout << "Truck" << endl;
    // }
};