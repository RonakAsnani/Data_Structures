// #include <bits/stdc++.h>
// using namespace std;

// int subs(string input, string output[])
// {
//     if (input.size() == 0)
//     {
//         output[0] = "";
//         return 1;
//     }
//     string smallstr = input.substr(1);
//     int small = subs(smallstr, output);

//     for (int i = 0; i < small; i++)
//     {
//         output[i + small] = input[0] + output[i];
//     }
//     return 2 * small;
// }

// int main()
// {
//     string input;
//     cin >> input;
//     int x = input.size();
//     string *output = new string[10000];
//     int count = subs(input, output);

//     for (int i = 0; i < count; i++)
//     {
//         cout << output[i] << endl;
//     }
// }

#include <bits/stdc++.h>
using namespace std;

int subs(string str, string out[])
{
    if (str.empty())
    {
        out[0] = "";
        return 1;
    }
    string smallstr = str.substr(1);
    int small = subs(smallstr, out);

    for (int i = 0; i < small; i++)
    {
        out[i + small] = out[i] + str[0];
    }
    return 2 * small;
}

int main()
{
    string str;
    cin >> str;
    string *out = new string[1000];

    int count = subs(str, out);
    for (int i = 0; i < count; i++)
    {
        cout << out[i] << endl;
    }
    return 0;
}