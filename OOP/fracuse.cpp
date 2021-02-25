#include <bits/stdc++.h>
using namespace std;
#include "Fraction.cpp"
int main()
{
    // Fraction f1(10, 4);
    // Fraction f2(15, 4);

    // // Fraction const f3;
    // // cout << f3.getNumerator() << f3.getDenomenator() << endl;

    // //f3.setnum(2);

    // Fraction f3 = f1.add(f2);
    // Fraction f4 = f1 + f2;
    // f4.print();
    // f1.print();
    // f2.print();
    // f3.print();

    // Fraction f5 = f1 * f2;
    // f5.print();
    // if (f1 == f2)
    // {
    //     cout << "equal" << endl;
    // }
    // else
    // {
    //     cout << "not equal" << endl;
    // }

    Fraction f1(10, 2);
    Fraction f2(15, 4);
    (f1 += f2) += f2;
    f1.print();
    f2.print();

    // Fraction f3 = f1++;
    // f1.print();
    // f3.print();

    // f1.print();
    // Fraction f3 = ++(++f1);
    // f1.print();
    // f3.print();
    // // ++f1;
    // f1.print();

    // Fraction f3 = ++f1;
    // f1.print();
    // f3.print();
    return 0;
}