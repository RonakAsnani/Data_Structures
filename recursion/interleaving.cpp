#include <bits/stdc++.h>
using namespace std;

void prin(string s, string t, string out)
{
    if (s.empty())
    {
        cout << out + t << endl;
        return;
    }
    if (t.empty())
    {
        cout << out + s << endl;
    }
    prin(s.substr(1), t, out + s[0]);
    prin(s, t.substr(1), out + t[0]);
}

int main()
{
    string s, t;
    cin >> s;
    cin >> t;

    string out = "";
    prin(s, t, out);
    return 0;
}