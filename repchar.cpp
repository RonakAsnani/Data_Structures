#include <bits/stdc++.h>
using namespace std;

void rep(string *str, char a, char b)
{
    if (str.size() == 0)
    {
        return;
    }
    if (str[0] == a)
    {
        str[0] = b;
    }
    else
    {
        str[0] = str[0];
    }
    rep(str.substr(1), a, b);
}

int main()
{
    string str;
    cin >> str;
    char a, b;
    cin >> a >> b;

    rep(&str, a, b);
    cout << str;
    return 0;
}