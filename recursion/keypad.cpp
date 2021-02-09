#include <bits/stdc++.h>
using namespace std;

string pad(int key)
{
    unordered_map<int, string> dial;
    dial[0] = "";
    dial[1] = "";
    dial[2] = "abc";
    dial[3] = "def";
    dial[4] = "ghi";
    dial[5] = "jkl";
    dial[6] = "mno";
    dial[7] = "pqrs";
    dial[8] = "tuv";
    dial[9] = "wxyz";

    return dial[key];
}

void key(int str, string out)
{
    if (str == 0)
    {
        cout << out << endl;
        return;
    }

    string x = pad(str % 10);

    for (int i = 0; i < x.size(); i++)
    {
        key(str / 10, out + x[i]);
    }
}

int main()
{
    int str;
    cin >> str;

    string out = "";
    key(str, out);
    return 0;
}