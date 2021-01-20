#include <bits/stdc++.h>
using namespace std;

int count(string str, string out[])
{
}

int main()
{
    string str;
    cin >> str;

    string *out = new string[1000];

    int x = count(str, out);
    for (int i = 0; i < x; i++)
    {
        cout << out[i] << endl;
    }
    return 0;
}