#include <bits/stdc++.h>
using namespace std;
#include "Pair.cpp"

int main()
{
    Pair<Pair<int, int>, int> p1;
    p1.setY(10);
    Pair<int, int> p2;
    p2.setX(5);
    p2.setY(6);

    p1.setX(p2);

    cout << p1.getY() << " " << p1.getX().getX() << " " << p1.getX().getY();

    return 0;
}