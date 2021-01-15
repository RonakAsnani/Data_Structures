#include <bits/stdc++.h>
using namespace std;

// string reverse(string str)
// {
//     int n = str.length();

//     // Swap character starting from two
//     // corners
//     for (int i = 0; i < n / 2; i++)
//         swap(str[i], str[n - i - 1]);
//     return str;
// }

int main()
{
    string str;
    getline(cin, str);
    string s = "";
    string s1 = "";
    for (int i = 0; i < str.length(); i++)
    {
        s1 = s1 + str[i];
        //cout << s1;
        if (str[i] == ' ' || str[i] == '\0')
        {
            s += s1;
            s1 = "";
            reverse(s.begin(), s.end());
            cout << s << " ";
        }
    }
    return 0;
}