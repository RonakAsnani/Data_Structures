#include <bits/stdc++.h>
using namespace std;
#include "Pair.cpp"

int main()
{
    // Pair<int> p1;

    // p1.setX(10);
    // p1.setY(20);

    // cout << p1.getX() << " " << p1.getY() << endl;
    // Pair<double> p2;
    // p2.setX(100.34);
    // p2.setY(34.21);
    // cout << p2.getX() << " " << p2.getY() << endl;

    // Pair<char> p3;

    // Pair<int, double> p1;
    // p1.setX(100.34);
    // p1.setY(100.34);
    // cout << p1.getX() << " " << p1.getY() << endl;

    Pair<Pair<int, int>, int> p1;
    p1.setY(10);
    Pair<int, int> p2;
    p2.setX(5);
    p2.setY(6);

    p1.setX(p2);

    cout << p1.getY() << " " << p1.getX().getX() << " " << p1.getX().getY();

    return 0;
}