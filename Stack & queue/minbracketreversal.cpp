/*Minimum bracket Reversal
Given a string expression which consists only ‘}’ and ‘{‘. The expression may not be balanced. You need to find the minimum number of bracket reversals which are required to make the expression balanced.
Return -1 if the given expression can't be balanced.
Input Format :
String S
Output Format :
Required count
Sample Input 1 :
{{{
Sample Output 1 :
-1
Sample Input 2 :
{{{{}}
Sample Output 2 :
1
*/

#include <bits/stdc++.h>
using namespace std;

int minbracket(string s)
{
    int x = s.length();
    stack<char> a1;
    stack<char> a2;
    for (int i = 0; i < x; i++)
    {
        if (s[i] == '{')
        {
            a1.push(s[i]);
        }
        if (s[i] == '}')
        {
            a2.push(s[i]);
        }
    }

    if (x % 2 != 0)
    {
        return -1;
    }
    else
    {
        if (a1.size() == a2.size())
        {
            return 0;
        }
        if (a1.size() > a2.size())
        {
            return (a1.size() - a2.size()) / 2;
        }
        else
        {
            return (a2.size() - a1.size()) / 2;
        }
    }
    return -1;
}
