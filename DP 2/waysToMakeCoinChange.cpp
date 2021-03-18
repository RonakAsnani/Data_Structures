/*
Ways To Make Coin Change
You are given an infinite supply of coins of each of denominations D = {D0, D1, D2, D3, ...... Dn-1}. You need to figure out the total number of ways W, in which you can make change for Value V using coins of denominations D.
Note : Return 0, if change isn't possible.
Input Format
Line 1 : Integer n i.e. total number of denominations
Line 2 : N integers i.e. n denomination values
Line 3 : Value V
Output Format
Line 1 :  Number of ways i.e. W
Constraints :
1<=n<=10
1<=V<=1000
Sample Input 1 :
3
1 2 3
4
Sample Output
4
Sample Output Explanation :
Number of ways are - 4 total i.e. (1,1,1,1), (1,1, 2), (1, 3) and (2, 2).*/

#include <bits/stdc++.h>
using namespace std;

int ways(int n, int a[], int v)
{
    int table[v + 1][n];
    for (int i = 0; i < n; i++)
    {
        table[0][i] = 1;
    }
    for (int i = 1; i < v + 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x = ((i - a[j]) >= 0) ? table[i - a[j]][j] : 0;
            int y = (j >= 1) ? table[i][j - 1] : 0;
            table[i][j] = x + y;
        }
        }
    return table[v][n - 1];
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
    int v;
    cin >> v;
    cout << ways(n, a, v) << endl;
    return 0;
}