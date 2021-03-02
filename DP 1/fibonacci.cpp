#include <bits/stdc++.h>
using namespace std;

int fibo(int n)
{
    if (n <= 1)
    {
        return n;
    }
    int a = fibo(n - 1);
    int b = fibo(n - 2);
    return a + b;
}

// memoization
int fib_better(int n, int *ans)
{
    if (n <= 1)
    {
        ans[n] = n;
        return n;
    }
    if (ans[n - 1] == 0)
    {
        int a = fib_better(n - 1, ans);
        ans[n - 1] = a;
    }
    if (ans[n - 2] == 0)
    {
        ans[n - 2] = fib_better(n - 2, ans);
    }
    ans[n] = ans[n - 1] + ans[n - 2];
    return ans[n];
}
int fib_better(int n)
{
    int *ans = new int[n];
    for (int i = 0; i < n; i++)
    {
        ans[i] = 0;
    }
    return fib_better(n, ans);
}

// dynamic programing
int fibo_dp(int n)
{
    int *ans = new int[n + 1];
    ans[0] = 0;
    ans[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        ans[i] = ans[i - 1] + ans[i - 2];
    }
    return ans[n];
}

int main()
{
    int n;
    cin >> n;
    cout << fib_better(n) << endl;
    cout << fibo(n) << endl;
    return 0;
}