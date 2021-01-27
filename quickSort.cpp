#include <bits/stdc++.h>
using namespace std;

int part(int a[], int st, int en)
{
    int pivot = a[st];
    int x = 0;
    for (int i = st + 1; i < en; i++)
    {
        if (a[i] <= pivot)
        {
            x++;
        }
    }
    int pi = x + st;
    int temp = a[st];
    a[st] = a[pi];
    a[pi] = temp;

    int i = st, j = en;
    while (i <= pi && j >= pi)
    {
        while (a[i] <= pivot)
        {
            i++;
        }
        while (a[j] >= pivot)
        {
            j--;
        }
        if (i < pi && j > pi)
        {
            int wen = a[i];
            a[i] = a[j];
            a[j] = wen;
            i++;
            j--;
        }
    }
    return pi;
}

void qui(int a[], int st, int en)
{
    if (st >= en)
    {
        return;
    }
    int pivot = part(a, st, en);
    qui(a, st, pivot - 1);
    qui(a, pivot + 1, en);
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    qui(a, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}