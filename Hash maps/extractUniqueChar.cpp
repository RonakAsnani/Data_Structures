/*  
Extract Unique characters
Given a string, you need to remove all the duplicates. That means, the output string should contain each character only once. The respective order of characters should remain same.
Input format :
String S
Output format :
Output String
Constraints :
0 <= Length of S <= 10^8
Sample Input 1 :
ababacd
Sample Output 1 :
abcd
Sample Input 2 :
abcde
Sample Output 2 :
abcde*/

#include <bits/stdc++.h>
using namespace std;

string remove(string s)
{
    unordered_map<char, char> m;
    string a = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (m.count(s[i]) == 0)
        {
            m[s[i]] = s[i];
            a += s[i];
        }
        else
        {
            continue;
        }
    }
    return a;
}

int main()
{
    string s;
    cin >> s;
    s = remove(s);
    cout << s;
    return 0;
}