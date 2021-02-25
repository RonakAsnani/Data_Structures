#include <bits/stdc++.h>
using namespace std;
#include "car.cpp"

class HondaCity : public Car
{
public:
    HondaCity(int x, int y) : Car(x, y)
    {
        cout << "Honda city parametrize3d constructor" << endl;
    }
    ~HondaCity()
    {
        cout << "Honda city destructor" << endl;
    }
};