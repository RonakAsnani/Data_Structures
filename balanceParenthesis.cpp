#include <bits/stdc++.h>
using namespace std;

bool check(char *a, int s)
{

    stack<char> s1;
    for (int i; i < s; i++)
    {

        if (a[i] == '{' || a[i] == '[' || a[i] == '(')
        {
            s1.push(a[i]);
        }
        if (a[i] == '}' || a[i] == ']' || a[i] == ')')
        {

            if (s1.empty())
            {
                return false;
            }
            if (a[i] == ']' && s1.top() == '[')
            {
                s1.pop();
            }
            else if (a[i] == '}' && s1.top() == '{')
            {
                s1.pop();
            }
            else if (a[i] == ')' && s1.top() == '(')
            {
                s1.pop();
            }
            else
            {
                return false;
            }
        }
    }
    return s1.empty();
}

int main()
{
    char *a = new char[19];
    for (int i = 0; i < 19; i++)
    {
        cin >> a[i];
    }
    cout << check(a, 19);
    return 0;
}