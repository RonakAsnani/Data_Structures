/*  
Code : Balanced Parenthesis
Given a string expression, check if brackets present in the expression are balanced or not. Brackets are balanced if the bracket which opens last, closes first.
You need to return true if it is balanced, false otherwise.
Note: This problem was asked in initial rounds in Facebook
Sample Input 1 :
{ a + [ b+ (c + d)] + (e + f) }
Sample Output 1 :
true
Sample Input 2 :
{ a + [ b - c } ]
Sample Output 2 :
false*/

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
