#include <bits/stdc++.h>
using namespace std;

void len(string s, int k, string out)
{
    if (k == 0)
    {
        cout << out << endl;
        return;
    }
    for (int i = 0; i < s.size(); i++)
    {
        //len(s.substr(1), k - 1, out);
        len(s, k - 1, out + s[i]);
    }
    //

    // len(s.substr(1), k - 1, out + s[1]);
    // len(s.substr(1), k - 1, out + s[2]);
}

int main()
{
    int k;
    cin >> k;
    string s;
    cin >> s;

    string out = "";

    len(s, k, out);

    return 0;
}