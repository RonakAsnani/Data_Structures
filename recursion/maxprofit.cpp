#include <bits/stdc++.h>
using namespace std;

int maxpro(int a[], int n)
{
    if (n == 0)
    {
        return 0;
    }

    maxpro(a, n - 1);
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
    int ans = maxpro(a, n);
    cout << ans;
    return 0;
}