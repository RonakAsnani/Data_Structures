#include <bits/stdc++.h>
using namespace std;

bool sorted(int a[], int n)
{
    if (n == 0 || n == 1)
    {
        return 0;
    }
    if (a[0] > a[1])
    {
        return false;
    }
    else
    {
        return true;
    }
    bool ans = sorted(a + 1, n - 1);
    if (!ans)
    {
        return false;
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

    if (sorted(a, n))
    {
        cout << true;
    }

    return 0;
}