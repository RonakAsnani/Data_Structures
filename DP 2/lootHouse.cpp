/*
Loot Houses
A thief wants to loot houses. He knows the amount of money in each house. He cannot loot two consecutive houses. Find the maximum amount of money he can loot.
Input Format
Line 1 : An integer N 
Line 2 : N spaced integers denoting money in each house
Output Format
 Line 1 : Maximum amount of money looted
Input Constraints
1 <= n <= 10^4
1 <= A[i] < 10^4
Sample Input :
6
5 5 10 100 10 5
Sample Output 1 :
110*/

#include <bits/stdc++.h>
using namespace std;

int maxmoney(int n, int *money)
{
    if (n <= 0)
    {
        return 0;
    }

    int x = maxmoney(n - 2, money + 2) + money[0];
    int y = maxmoney(n - 1, money + 1);
    return max(x, y);
}
// memoization
int maxMoney_better(int n, int *money)
{
    if (n == 0)
    {
        return 0;
    }
    int dp[n];
    dp[0] = money[0];
    dp[1] = max(money[0], money[1]);

    for (int i = 2; i < n; i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + money[i]);
    }
    return dp[n - 1];
}
int main()
{
    int n;
    cin >> n;
    int *money = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> money[i];
    }
    // int **b = new int *[n];
    // for (int i = 0; i < n; i++)
    // {
    //     b[i] = new int[n-1];
    //     for (int j = 0; j < n-1; j++)
    //     {
    //         b[i][j] = -1;
    //     }
    // }

    cout << maxMoney_better(n, money) << endl;
    cout << maxmoney(n, money) << endl;
    return 0;
}