/*
Code : Minimum Count
Given an integer N, find and return the count of minimum numbers, sum of whose squares is equal to N.
That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. Output will be 1, as 1 is the minimum count of numbers required.
Note : x^y represents x raise to the power y.
Input Format :
Integer N
Output Format :
Required minimum count
Constraints :
1 <= N <= 1000
Sample Input 1 :
12
Sample Output 1 :
3
Sample Output 1 Explanation :
12 can be represented as :
1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1
1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 2^2
1^1 + 1^1 + 1^1 + 1^1 + 2^2 + 2^2
2^2 + 2^2 + 2^2
As we can see, the output should be 3.
Sample Input 2 :
9
Sample Output 2 :
1*/

#include <bits/stdc++.h>
using namespace std;
// brute force
int mcount(int n)
{
    if (n == 0)
    {
        return 0;
    }

    int m = INT_MAX;
    for (int i = 1; i <= sqrt(n); i++)
    {
        m = min(m, mcount(n - i * i));
    }
    return m + 1;
}
// memoization
int mcount(int n, int *ans)
{
    if (n == 0)
    {
        return 0;
    }
    int m = INT_MAX;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (ans[n - i * i] == 0)
        {
            ans[n - i * i] = mcount(n - i * i);
        }
        m = min(m, ans[n - i * i]);
    }
    return m + 1;
}

int main()
{
    int n;
    cin >> n;
    int *ans = new int[n + 1];
    // for (int i = 0; i <= n; i++)
    // {
    //     ans[i] = 0;
    // }
    // dp
    ans[0] = 0;
    ans[1] = 1;
    ans[2] = 2;
    ans[3] = 3;
    for (int i = 4; i <= n; i++)
    {
        int m = i;
        for (int j = 1; j <= i / 2; j++)
        {
            int k = i - j * j;
            if (k >= 0)
            {
                m = min(m, ans[k] + 1);
            }
            ans[i] = m;
        }
    }
    cout << ans[n] << endl;

    cout << mcount(n, ans) << endl;
    cout << mcount(n) << endl;
    return 0;
}