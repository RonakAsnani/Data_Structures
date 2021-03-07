/*
Code : Edit Distance
Given two strings s and t of lengths m and n respectively, find the Edit Distance between the strings. Edit Distance of two strings is minimum number of steps required to make one string equal to other. In order to do so you can perform following three operations only :
1. Delete a character

2. Replace a character with another one

3. Insert a character
Note - Strings don't contain spaces
Input Format :
Line 1 : String s
Line 2 : String t
Output Format :
Line 1 : Edit Distance value
Constraints
1<= m,n <= 10
Sample Input 1 :
abc
dc
Sample Output 1 :
2
*/

#include <bits/stdc++.h>
using namespace std;

int dist(string s, string t)
{
    if (s.size() == 0 || t.size() == 0)
    {
        if (s.size() > t.size())
        {
            return s.size();
        }
        else
        {
            return t.size();
        }
    }
    if (s[0] == t[0])
    {
        return dist(s.substr(1), t.substr(1));
    }
    else
    {
        int a = dist(s.substr(1), t);
        int b = dist(s, t.substr(1));
        int c = dist(s.substr(1), t.substr(1));
        return 1 + min(a, min(b, c));
    }
}

// memoization
int dist_memo(string s, string t, int **a)
{
    if (s.size() == 0 || t.size() == 0)
    {
        if (s.size() > t.size())
        {
            return s.size();
        }
        else
        {
            return t.size();
        }
    }
    int m = s.size();
    int n = t.size();
    if (a[m][n] != -1)
    {
        return a[m][n];
    }
    int ans;

    if (s[0] == t[0])
    {
        a[m - 1][n - 1] = dist_memo(s.substr(1), t.substr(1), a);
        a[m][n] = a[m - 1][n - 1];
    }
    else
    {
        int x = dist_memo(s.substr(1), t, a);
        int y = dist_memo(s, t.substr(1), a);
        int z = dist_memo(s.substr(1), t.substr(1), a);
        a[m - 1][n] = x;
        a[m][n - 1] = y;
        a[m - 1][n - 1] = z;
        a[m][n] = min(x, min(y, z)) + 1;
    }
    return a[m][n];
}
// dp
int dist_dp(string s, string t)
{
    int m = s.length();
    int n = t.length();
    int **a = new int *[m + 1];
    for (int i = 0; i <= m; i++)
    {
        a[i] = new int[n + 1];
    }
    for (int i = 0; i <= m; i++)
    {
        a[i][0] = i;
    }
    for (int i = 0; i <= n; i++)
    {
        a[0][i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[m - i] == t[n - j])
            {
                a[i][j] = a[i - 1][j - 1];
            }
            else
            {
                int x = a[i - 1][j];
                int y = a[i][j - 1];
                int z = a[i - 1][j - 1];
                a[i][j] = min(x, min(y, z)) + 1;
            }
        }
    }
    return a[m][n];
}

int main()
{
    string s = "tyuftyfcu", t = "yfutyv";

    int **ans = new int *[s.length() + 1];
    for (int i = 0; i <= s.length(); i++)
    {
        ans[i] = new int[t.length() + 1];
        for (int j = 0; j <= t.length(); j++)
        {
            ans[i][j] = -1;
        }
    }
    cout << dist_dp(s, t) << endl;
    cout << dist_memo(s, t, ans) << endl;
    cout << dist(s, t) << endl;
    return 0;
}