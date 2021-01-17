#include <bits/stdc++.h>
using namespace std;

void removedup(char a[])
{
    if (a[0] == '\0')
    {
        return;
    }
    if (a[0] != a[1])
    {
        removedup(a + 1);
    }
    else
    {
        int i = 1;
        for (; a[i] != '\0'; i++)
        {
            a[i - 1] = a[i];
        }
        a[i - 1] = a[i];
        removedup(a);
    }
}

int main()
{
    char a[100];
    cin >> a;
    removedup(a);
    cout << a << endl;
    return 0;
}