#include <bits/stdc++.h>
using namespace std;

void pri(int n, int a, int x)
{
    if (n == 0)
    {
        cout << x << endl;
        return;
    }
    for (int i = (a + 1); i <= 9; i++)
    {
        pri(x * 10 + i, i, n - 1);
    }
}

int main()
{
    int n;
    cin >> n;
    int x = 0;
    pri(n, 0, x);
    return 0;
}