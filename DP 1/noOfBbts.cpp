/*Code : No. of balanced BTs
Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.
This number can be huge, so return output modulus 10^9 + 7.
Write a simple recursive solution.
Input Format :
Integer h
Output Format :
Count % 10^9 + 7
Input Constraints :
1 <= h <= 40
Sample Input 1:
3
Sample Output 1:
15
Sample Input 2:
4
Sample Output 2:
315*/

#include <bits/stdc++.h>
using namespace std;

int no(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    int mod = pow(10, 9) + 7;

    int x = no(n - 1);
    int y = no(n - 2);
    int temp1 = (int)(((long)x * x) % mod);
    int temp2 = (int)((2 * (long)x * y) % mod);
    int ans = (temp1 + temp2) % mod;
    return ans;
    //return x * x + 2 * x * y;
}

// memoization

int no(int n, int *ans)
{
    if (n <= 1)
    {
        return 1;
    }

    if (ans[n - 1] == 0)
    {
        ans[n - 1] = no(n - 1, ans);
    }
    if (ans[n - 2] == 0)
    {
        ans[n - 2] = no(n - 2, ans);
    }
    int x = ans[n - 1];
    int y = ans[n - 2];
    int mod = (int)pow(10, 9) + 7;
    int temp1 = (int)(((long)x * x) % mod);
    int temp2 = (int)((2 * (long)x * y) % mod);
    int a = (temp1 + temp2) % mod;
    return a;
}

int binaryTreesOfHeightH(int h)
{
    // Write your code here
    int mod = (pow(10, 9)) + 7;
    int dp[h + 1];
    //base cases
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= h; i++)
    {
        dp[i] = ((long)dp[i - 1] * ((2 * (long)dp[i - 2]) % mod + dp[i - 1]) % mod) % mod;
    }
    return dp[h];
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
    ans[0] = 1;
    ans[1] = 1;
    ans[2] = 3;
    for (int i = 3; i <= n; i++)
    {
        int x = ans[i - 1];
        int y = ans[i - 2];
        int mod = (int)(pow(10, 9)) + 7;

        ans[i] = x * x + 2 * x * y;
    }
    cout << ans[n] << endl;
    // cout << no(n, ans);

    return 0;
}