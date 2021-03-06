/**/

#include <bits/stdc++.h>
using namespace std;

int getPath(int **a, int m, int n, int row, int col)
{
    if (row == m - 1 && col == n - 1)
    {
        return a[row][col];
    }

    int x = INT_MAX, y = INT_MAX, z = INT_MAX;
    if (row != m - 1)
    {
        x = getPath(a, m, n, row + 1, col);
    }
    if (col != n - 1)
    {
        y = getPath(a, m, n, row, col + 1);
    }
    if (col != n - 1 && row != m - 1)
    {
        z = getPath(a, m, n, row + 1, col + 1);
    }
    return min(x, min(y, z)) + a[row][col];
    ;
}

// memoization
int betterPath(int **a, int m, int n, int row, int col, int **ans)
{
    if (row == m - 1 && col == n - 1)
    {
        return a[row][col];
    }
    if (row >= m || col >= n)
    {
        return INT_MAX;
    }
    if (ans[row][col] != -1)
    {
        return ans[row][col];
    }
    int x = betterPath(a, m, n, row + 1, col, ans);
    if (x < INT_MAX)
    {
        ans[row + 1][col] = x;
    }
    int y = betterPath(a, m, n, row, col + 1, ans);
    if (y < INT_MAX)
    {
        ans[row][col + 1] = y;
    }
    int z = betterPath(a, m, n, row + 1, col + 1, ans);
    if (z < INT_MAX)
    {
        ans[row + 1][col + 1] = z;
    }
    ans[row][col] = min(x, min(y, z)) + a[row][col];
    return ans[row][col];
}

// dp
int getpathdp(int **a, int m, int n)
{
    int b[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            b[i][j] = INT_MAX;
        }
    }
    // b[m - 1][m - 1] = a[m - 1][n - 1];
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            int x = INT_MAX, y = INT_MAX, z = INT_MAX;
            if (i < m - 1)
            {
                x = b[i + 1][j];
            }
            if (j < n - 1)
            {
                y = b[i][j + 1];
            }
            if (i < m - 1 && j < n - 1)
            {
                x = b[i + 1][j + 1];
            }
            int g = min(x, min(y, z));
            if (g < INT_MAX)
            {
                b[i][j] = g + a[i][j];
            }
            else
            {
                b[i][j] = a[i][j];
            }
        }
    }
    return b[0][0];
}

int path(int **a, int m, int n)
{
    return getPath(a, m, m, 0, 0);
}
int main()
{
    int m, n;
    cin >> m >> n;
    int **a = new int *[m];
    int **b = new int *[m];
    for (int i = 0; i < m; i++)
    {
        a[i] = new int[n];
        b[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            b[i][j] = -1;
        }
    }
    int ans = getpathdp(a, m, n);
    cout << ans << endl;

    return 0;
}