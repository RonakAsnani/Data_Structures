/*Check redundant brackets
Given a string mathematical expression, return true if redundant brackets are present in the expression. Brackets are redundant if there is nothing inside the bracket or more than one pair of brackets are present.
Assume the given string expression is balanced and contains only one type of bracket i.e. ().
Note: You will not get partial score for this problem. You will get marks only if all test cases are passed.
Input Format :
String s (Expression)
Output Format :
true or false
Sample Input 1:
((a + b)) 
Sample Output 1:
true
Sample Input 2:
(a+b) 
Sample Output 2:
false
*/

// not working
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
