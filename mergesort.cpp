#include <bits/stdc++.h>
using namespace std;

void merge(int a[], int st, int mid, int en)
{
    int temp[en - st];
    int k = 0;
    int i = st, j = mid + 1;
    while (i <= mid && j <= en)
    {
        if (a[i] < a[j])
        {
            temp[k++] = a[i++];
        }
        else
        {
            temp[k++] = a[j++];
        }
    }
    if (i <= mid)
    {
        while (i <= mid)
        {
            temp[k++] = a[i++];
        }
    }
    else if (j <= en)
    {
        while (j <= en)
        {
            temp[k++] = a[j++];
        }
    }

    k = 0;
    for (int i = st; i < en; i++)
    {
        a[i] = temp[k++];
    }
}

void mergesort(int a[], int st, int en)
{
    if (st >= en)
    {
        return;
    }
    int mid = (st + en) / 2;

    mergesort(a, st, mid);
    mergesort(a, mid + 1, en);
    merge(a, st, mid, en);
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
    mergesort(a, 1, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}