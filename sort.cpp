#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int b[3];
    b[0] = 0;
    b[1] = 1;
    b[2] = 2;

    for (int i = 0; i < n; i++)
    {
        b[a[i]]++;
    }
    int d[b[0]], e[b[1]], f[b[2]];

    for (int i = 0; i < b[0]; i++)
    {
        d[i] = 0;
    }
    for (int i = 0; i < b[1]; i++)
    {
        e[i] = 1;
    }
    for (int i = 0; i < b[2]; i++)
    {
        f[i] = 2;
    }

    for (int i = 0; i < b[0]; i++)
    {
        cout << d[i];
    }
    for (int i = 0; i < b[1]; i++)
    {
        cout << e[i];
    }
    for (int i = 0; i < b[2]; i++)
    {
        cout << f[i];
    }

    return 0;
}