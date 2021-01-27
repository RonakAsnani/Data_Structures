#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         if (a[j] < a[i])
    //         {
    //             int temp = a[j];
    //             a[j] = a[i];
    //             a[i] = temp;
    //         }
    //     }
    // }

    // int c = 0;
    // while (c < n - 1)
    // {
    //     for (int i = 0; i < n - c; i++)
    //     {
    //         if (a[i] > a[i + 1])
    //         {
    //             int temp = a[i];
    //             a[i] = a[i + 1];
    //             a[i + 1] = temp;
    //         }
    //     }
    //     c++;
    // }

    // for(int i=1;i<n;i++){
    //     int x = a[i];
    //     int j = i-1;
    //     while(a[j] > x && j>=0){
    //         a[j+1] = a[j];
    //         j--;
    //     }
    //     a[j+1] = x;
    // }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}