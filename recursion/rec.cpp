#include <bits/stdc++.h>
using namespace std;

void removeX(char a[])
{
    if (a[0] == '\0')
    {
        return;
    }
    if (a[0] != 'x')
    {
        removeX(a + 1);
    }
    else
    {
        int i = 1;
        for (; a[i] != '\0'; i++)
        {
            a[i - 1] = a[i];
        }
        a[i - 1] = a[i];
        removeX(a);
    }
}

int len(char a[])
{
    if (a[0] == '\0')
    {
        return 0;
    }
    int small = len(a + 1);
    return small + 1;
}

int main()
{

    char a[100];
    cin >> a;
    int x = len(a);
    cout << x << endl;
    removeX(a);
    cout << a << endl;
    x = len(a);
    cout << x;
    return 0;
}