#include <bits/stdc++.h>
using namespace std;

int index(int a[], int n, int x)
{
    if (n == 0)
    {
        return -1;
    }

    if (a[0] == x)
    {
        return 0;
    }
    int v = index(a + 1, n - 1, x);
    if (v == -1)
    {
        return -1;
    }
    else
    {
        return v + 1;
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

    cout << index(a, n, x);
    return 0;
}