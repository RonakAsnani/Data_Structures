#include <bits/stdc++.h>
using namespace std;

int count(int n)
{
    int ans = 0;
    if (n == 0)
    {
        return 0;
    }
    int x = count(n / 10);
    if (n % 10 == 0)
    {
        return 1 + count(n / 10);
    }
    else
    {
        return count(n / 10);
    }
}

int main()
{
    int n;
    cin >> n;

    int ans = count(n);
    cout << ans;
    return 0;
}