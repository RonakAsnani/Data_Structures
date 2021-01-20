#include <bits/stdc++.h>
using namespace std;

int number(string str)
{
    if (str.empty())
    {
        return 0;
    }
    number(str.substr(1));

    int ans = 0;
    ans = (str[0] - 24) * pow(10, str.length() - 1);
    return ans;
}

int main()
{
    string str;
    cin >> str;

    cout << number(str) << endl;
    return 0;
}