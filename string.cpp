#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[10];

    a[0] = 5;
    a[1] = 12;
    cout << *a << endl;

    int *p = &a[0];

    cout << a << endl;
    cout << p << endl;

    cout << &p << endl;
    cout << &a << endl;

    cout << sizeof(p) << " " << sizeof(a);

    p = p + 1;
}