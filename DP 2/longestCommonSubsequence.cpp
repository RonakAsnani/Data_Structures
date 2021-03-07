#include <bits/stdc++.h>
using namespace std;

int lcs(string s, string t)
{
    // base case
    if (s.length() == 0 || t.length() == 0)
    {
        return 0;
    }

    // recursive
    if (s[0] == t[0])
    {
        return 1 + lcs(s.substr(1), t.substr(1));
    }
    else
    {
        int a = lcs(s.substr(1), t);
        int b = lcs(s, t.substr(1));
        int c = lcs(s.substr(1), t.substr(1));
        return max(a, max(b, c));
    }
}
int lcs_memo(string s, string t, int **ans)
{
    if (s.size() == 0 || t.size() == 0)
    {
        return 0;
    }
    int m = s.size();
    int n = t.size();

    if (ans[m][n] != -1)
    {
        return ans[m][n];
    }
    if (s[0] == t[0])
    {
        ans[m - 1][n - 1] = lcs_memo(s.substr(1), t.substr(1), ans);
        ans[m][n] = 1 + ans[m - 1][n - 1];
    }
    else
    {
        ans[m][n - 1] = lcs_memo(s, t.substr(1), ans);
        ans[m - 1][n] = lcs_memo(s.substr(1), t, ans);
        ans[m][n] = max(ans[m - 1][n], ans[m][n - 1]);
    }
    return ans[m][n];
}

int lcs_better(string s, string t, int **ans)
{
    if (s.size() == 0 || t.size() == 0)
    {
        return 0;
    }
    int m = s.length();
    int n = t.length();
    if (ans[m][n] != -1)
    {
        return ans[m][n];
    }
    if (s[0] == t[0])
    {
        ans[m - 1][n - 1] = lcs_better(s.substr(1), t.substr(1), ans);
        ans[m][n] = ans[m - 1][n - 1] + 1;
    }
    else
    {
        ans[m][n - 1] = lcs_better(s, t.substr(1), ans);
        ans[m - 1][n] = lcs_better(s.substr(1), t, ans);
        ans[m][n] = max(ans[m - 1][n], ans[m][n - 1]);
    }
    return ans[m][n];
}

int lcsDp(string s, string t)
{
    int m = s.size();
    int n = t.length();
    int **ans = new int *[m + 1];
    for (int i = 0; i <= m; i++)
    {
        ans[i] = new int[n + 1];
    }
    for (int j = 0; j <= n; j++)
    {
        ans[0][j] = 0;
    }
    for (int j = 0; j <= m; j++)
    {
        ans[j][0] = 0;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[m - i] == t[m - j])
            {
                ans[i][j] = 1 + ans[i - 1][j - 1];
            }
            else
            {
                ans[i][j] = max(ans[i - 1][j], ans[i][j - 1]);
            }
        }
    }
    return ans[m][n];
}

int main()
{
    string s1 = "huiewhiuaherwgrg";
    string s2 = "bfhbciuabrvervw";
    int m = s1.length();
    int n = s2.length();
    int **ans = new int *[m + 1];
    for (int i = 0; i < m + 1; i++)
    {
        ans[i] = new int[n + 1];
        for (int j = 0; j < n + 1; j++)
        {
            ans[i][j] = -1;
        }
    }
    cout << lcsDp(s1, s2) << endl;
    cout << lcs_memo(s1, s2, ans) << endl;
    cout << lcs(s1, s2) << endl;

    return 0;
}