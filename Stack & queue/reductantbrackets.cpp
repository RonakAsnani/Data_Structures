#include <bits/stdc++.h>
using namespace std;

bool reductant(string s)
{
    stack<char> s1;

    for (int i = 0; i < s.length(); i++)
    {
        bool flag = false;
        if (s[i] == '(')
        {
            s1.push(s[i]);
        }
        else
        {
            while (s[i] != ')')
            {
                s1.pop();
                flag = true;
                if (s1.empty())
                {
                    break;
                }
            }
            if (s1.empty())
            {
                continue;
            }
        }
    }
}

int main()
{
    string s;
    cin >> s;
    cout << reductant(s);
    return 0;
}