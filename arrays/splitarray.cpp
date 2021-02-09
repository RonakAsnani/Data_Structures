#include <bits/stdc++.h>
using namespace std;

bool split(int a[], int n, int left, int right, int st)
{
    if (st == n)
    {
        return left == right;
    }
    if (a[st] % 5 == 0)
    {
        left += a[st];
    }
    else if (a[st] % 3 == 0)
    {
        right += a[st];
    }
    else
    {
        return split(a, n, left + a[st], right, st + 1) || split(a, n, left, right + a[st], st + 1);
    }
    return split(a, n, left, right, st + 1);
}

bool splitarry(int a[], int n)
{
    return split(a, n, 0, 0, 0);
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
    bool z = splitarry(a, n);
    cout << z;
    return 0;
}