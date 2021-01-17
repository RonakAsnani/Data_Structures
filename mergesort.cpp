#include <bits/stdc++.h>
using namespace std;

// void merge(int a[], int si, int ei)
// {
//     int mid = (si + ei) / 2;
//     int c[mid];
//     int size2 = ei - mid;
//     int d[size2];
//     int k = 0;
//     for (int i = 0; i <= mid; i++)
//     {
//         c[k] = a[i];
//         k++;
//     }
//     int j = 0;
//     for (int i = mid + 1; i <= size2; i++)
//     {
//         d[j] = a[i];
//         j++;
//     }
//     k = 0;
//     j = 0;

//     int i = 0;
//     while (k < mid && j < size2)
//     {
//         if (c[k] < d[j])
//         {
//             a[i] = c[k];
//             k++;
//             i++;
//         }
//         else
//         {
//             a[i] = d[j];
//             j++;
//             i++;
//         }
//     }
// }

// void mergesort(int a[], int si, int ei)
// {
//     if (si >= ei)
//     {
//         return;
//     }
//     int mid = (si + ei) / 2;
//     mergesort(a, si, mid);
//     mergesort(a, mid + 1, ei);

//     merge(a, si, ei);
// }

// int main()
// {
//     int n;
//     cin >> n;
//     int a[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }
//     mergesort(a, 0, n - 1);
//     for (int i = 0; i < n; i++)
//     {
//         cout << a[i] << " ";
//     }
//     return 0;
// }

void merge(int a[], int l, int mid, int u)
{

    int size1 = mid - l + 1;
    int size2 = u - mid;

    int L1[size1];
    int L2[size2];

    int k = 0;
    for (int i = l; i <= mid; i++, k++)
        L1[k] = a[i];
    int j = 0;
    for (int i = mid + 1; i <= u; i++, j++)
        L2[j] = a[i];
    k = 0;
    j = 0;
    int i = l;
    while (k < size1 && j < size2)
    {

        if (L1[k] <= L2[j])
        {
            a[i] = L1[k++];
            i++;
        }
        else
        {
            a[i] = L2[j++];
            i++;
        }
    }

    while (k < size1)
    {
        a[i] = L1[k++];
        i++;
    }
    while (j < size2)
    {
        a[i] = L2[j++];
        i++;
    }
}
void mS(int a[], int l, int u)
{

    if (l < u)
    {
        int mid = (l + u) / 2;
        mS(a, l, mid);
        mS(a, mid + 1, u);
        merge(a, l, mid, u);
    }
}

void mergeSort(int input[], int size)
{
    // Write your code here
    int l = 0;
    int u = size - 1;

    mS(input, l, u);
}

int main()
{
    int input[1000], length;
    cin >> length;
    for (int i = 0; i < length; i++)
        cin >> input[i];
    mergeSort(input, length);
    for (int i = 0; i < length; i++)
    {
        cout << input[i] << " ";
    }
}