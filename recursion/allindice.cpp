#include <bits/stdc++.h>
using namespace std;

int index(int a[], int n, int x, int b[])
{
    if (n == 0)
    {
        return 0;
    }
    int ans = index(a, n - 1, x, b);
    if (a[n - 1] != x)
    {
        return ans;
    }
    else
    {
        b[ans] = n - 1;
        return ans + 1;
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
    int b[n];
    int size = index(a, n, x, b);
    for (int i = 0; i < size; i++)
    {
        cout << b[i];
    }
}