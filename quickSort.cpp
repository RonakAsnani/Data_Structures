#include <bits/stdc++.h>
using namespace std;

int partition(int a[], int st, int en)
{
    int x = 0;
    for (int i = st; i < en; i++)
    {

        if (a[st] > a[i])
        {

            x++;
        }
        int temp = a[x];
        a[x] = a[st];
        a[st] = temp;
    }

    int m = st;
    int n = x + 1;
    while (m < x && n < en)
    {
        if (a[m] > a[x] && a[n] < a[x])
        {
            int demp = a[n];
            a[n] = a[m];
            a[m] = demp;
        }
        else if (a[m] < a[x] && a[n] < a[x])
        {
            m++;
        }
        else if (a[n] > a[x] && a[m] > a[x])
        {
            n++;
        }
    }
    return x;

    // int pivot = a[u];
    // int pIndex = l;

    // for (int i = l; i < u; i++)
    // {

    //     if (pivot > a[i])
    //     {
    //         int temp = a[pIndex];
    //         a[pIndex] = a[i];
    //         a[i] = temp;
    //         pIndex++;
    //     }
    // }
    // int temp = a[pIndex];
    // a[pIndex] = a[u];
    // a[u] = temp;
    // return pIndex;
}

void quic(int a[], int st, int en)
{
    if (st >= en)
    {
        return;
    }
    int c = partition(a, st, en);
    quic(a, st, c - 1);
    quic(a, c + 1, en);
}
void qui(int a[], int n)
{
    quic(a, 0, n - 1);
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
    qui(a, n);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}