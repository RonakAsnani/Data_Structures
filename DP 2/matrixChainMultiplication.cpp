/*
Matrix Chain Multiplication
Given a chain of matrices A1, A2, A3,.....An, you have to figure out the most efficient way to multiply these matrices i.e. determine where to place parentheses to minimise the number of multiplications.
You will be given an array p[] of size n + 1. Dimension of matrix Ai is p[i - 1]*p[i]. You need to find minimum number of multiplications needed to multiply the chain.
Input Format :
Line 1 : Integer n i.e. number of matrices
Line 2 : n + 1 integers i.e. elements of array p[] 
Output Format :
Line 1 : Minimum number of multiplication needed
Constraints :
1 <= n <= 100
Sample Input 1 :
3
10 15 20 25
Sample Output :
8000
Sample Output Explanation :
There are two ways to multiply the chain - A1*(A2*A3) or (A1*A2)*A3.
If multiply in order A1*(A2*A3) then number of multiplications required are 15000.
If multiply in order (A1*A2)*A3 then number of multiplications required are 8000.
Thus minimum number of multiplications required are 8000
*/

#include <bits/stdc++.h>
using namespace std;

int mino(int *a, int s, int e)
{
    if (s == e || s == e - 1)
    {
        return 0;
    }
    int x = INT_MAX;
    int y = INT_MAX;
    int ans = INT_MAX;
    for (int i = s + 1; i < e; i++)
    {
        x = mino(a, s, i);
        y = mino(a, i, e);
        ans = min(x + y + a[s] * a[i] * a[e], ans);
    }
    return ans;
}
// memo
int minot(int *a, int s, int e, int **b)
{
    if (s == e || s == e - 1)
    {
        return 0;
    }
    int x = INT_MAX;
    int y = INT_MAX;
    int ans = INT_MAX;
    for (int i = s + 1; i < e; i++)
    {
        if (b[s][i] == -1)
        {
            b[s][i] = minot(a, s, i, b);
        }
        x = b[s][i];
        if (b[i][e] == -1)
        {
            b[i][e] = minot(a, i, e, b);
        }
        y = b[i][e];
        ans = min(x + y + a[s] * a[i] * a[e], ans);
    }
    return ans;
}
//dp
int dp(int *a, int s, int e)
{
    int m[e + 1][e + 1];
    for (int i = s; i <= e; i++)
    {
        m[i][i] = 0;
    }
}

int main()
{
    int n;
    cin >> n;
    int *a = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        cin >> a[i];
    }
    int **b = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        b[i] = new int[n + 1];
        for (int j = 0; j <= n; j++)
        {
            b[i][j] = -1;
        }
    }
    cout << minot(a, 0, n, b) << endl;
    cout << mino(a, 0, n) << endl;

    return 0;
}