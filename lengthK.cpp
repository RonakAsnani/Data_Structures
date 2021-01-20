#include <bits/stdc++.h>
using namespace std;

int len(string s, int k, string out[])
{
    if (s.size() == 0)
    {
        out[0] = "";
        return 1;
    }
    int small = len(s.substr(1), k, out);

    int m = 0;
    for (int i = 0; i < small; i++)
    {
        if (out[i].size() < k)
        {
            out[m] = out[i] + s[0];
            m++;
        }
    }
    return m;
}

int main()
{
    int k;
    cin >> k;
    string s;
    cin >> s;

    string *out = new string[1000];

    int count = len(s, k, out);

    for (int i = 0; i < count; i++)
    {
        cout << out[i] << endl;
    }
    return 0;
}