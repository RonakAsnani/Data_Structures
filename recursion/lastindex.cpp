#include <bits/stdc++.h>
using namespace std;

int index(int a[], int n, int x)
{
    if (n == 0)
    {
        return -1;
    }
    if (a[n - 1] == x)
    {
        return n - 1;
    }
    int v = index(a, n - 1, x);

    if (v == -1)
    {
        return -1;
    }
    else
    {
        return v;
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int x;
    cin >> x;
}