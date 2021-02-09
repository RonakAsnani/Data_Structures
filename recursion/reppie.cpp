#include <bits/stdc++.h>
using namespace std;

void pi(string str, string out)
{
    if (str.size() == 0)
    {
        cout << out << endl;
        return;
    }

    if (str[0] == 'p' && str[1] == 'i')
    {
        out += "3.14";
    }
    else if (str[1] != 'i' && str[0] != 'i')
    {
        out += str[0];
    }
    pi(str.substr(1), out);
}
int main()
{
    string str;
    string out = "";
    cin >> str;
    pi(str, out);
    return 0;
}