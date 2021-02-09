#include <bits/stdc++.h>
using namespace std;

int printkey(int num, string out[])
{
    if (num == 0)
    {
        out[0] = "";
        return 1;
    }
    int small = printkey(num / 10, out);

    string dail = "";

    if (num % 10 == 1)
    {
        dail += "";
    }
    if (num % 10 == 5)
    {
        dail += "jkl";
    }
    if (num % 10 == 2)
    {
        dail += "abc";
    }
    if (num % 10 == 3)
    {
        dail += "def";
    }
    if (num % 10 == 4)
    {
        dail += "ghi";
    }
    if (num % 10 == 6)
    {
        dail += "mno";
    }
    if (num % 10 == 7)
    {
        dail += "pqrs";
    }
    if (num % 10 == 8)
    {
        dail += "tuv";
    }
    if (num % 10 == 9)
    {
        dail += "wxyz";
    }
    int m = 0;
    for (int i = 0; i < small; i++)
    {
        for (int j = 0; j < dail.size(); j++)
        {
            out[m] = out[i] + dail[j];
            m++;
        }
    }

    return m;
}

int main()
{
    int num;
    cin >> num;

    string *out = new string[1000];
    int count = printkey(num, out);
    for (int i = 0; i < count; i++)
    {
        cout << out[i] << endl;
    }
    return 0;
}