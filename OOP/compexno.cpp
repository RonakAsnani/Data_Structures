#include <bits/stdc++.h>
using namespace std;
#include "ComplexNumbers.cpp"
int main()
{
    int real1, ima1, real2, ima2;
    cin >> real1 >> ima1;
    cin >> real2 >> ima2;

    ComplexNumbers c1(real1, ima1);
    ComplexNumbers c2(real2, ima2);

    int choice;
    cin >> choice;
    if (choice == 1)
    {
        c1.plus(c2);
        c1.print();
    }
    else if (choice == 2)
    {
        c1.multiply(c2);
        c1.print();
    }
    else
    {
        return 0;
    }
    return 0;
}