#include <bits/stdc++.h>
using namespace std;

int ways(int n)
{
    if (n == 1 || n == 0)
    {
        return 1;
    }
    if (n == 2)
    {
        return 2;
    }
    int a = ways(n - 1) + ways(n - 2) + ways(n - 3);
    return a;
}

int main()
{
    int n;
    cin >> n;

    int x = ways(n);
    cout << x;
    return 0;
}