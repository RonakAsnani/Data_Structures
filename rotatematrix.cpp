#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    int rs = 0, re = n - 1, cs = 0, ce = n - 1;
    while (ce >= 0)
    {
        for (int i = rs; i <= re; i++)
        {
            cout << a[i][ce];
        }
        cout << endl;
        ce--;
    }

    return 0;
}