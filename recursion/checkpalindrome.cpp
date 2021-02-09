#include <bits/stdc++.h>
using namespace std;

bool ch(string str, int st, int en)
{
    if (en < st)
    {
        return true;
    }
    if (str[st] != str[en])
    {
        return false;
    }

    bool ans = ch(str, st + 1, en - 1);
    return ans;
}

bool check(string str)
{
    int end = str.length() - 1;
    return ch(str, 0, end);
}

int main()
{
    string str;
    getline(cin, str);

    if (check(str))
    {
        cout << true;
    }
    else
    {
        cout << false;
    }
    return 0;
}