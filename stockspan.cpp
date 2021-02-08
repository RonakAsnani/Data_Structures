#include <bits/stdc++.h>
using namespace std;

int *stockspan(int *a, int n)
{
    int *output = new int[n];
    stack<int> s1;
    // for (int i = 0; i < n; i++)
    // {
    //     int count = 0;
    //     for (int j = i; j >= 0; j--)
    //     {
    //         if (a[i] >= a[j])
    //         {
    //             count++;
    //         }
    //         else
    //         {
    //             break;
    //         }
    //     }
    //     output[i] = count;
    // }

    s1.push(0);
    output[0] = 1;
    for (int i = 1; i < n; i++)
    {
        while (!s1.empty() && a[s1.top()] <= a[i])
        {
            s1.pop();
        }
        if (s1.empty())
        {
            output[i] = i + 1;
        }
        else
        {
            output[i] = i - s1.top();
        }
        s1.push(i);
    }
    return output;
}

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int *b = stockspan(a, n);

    for (int i = 0; i < n; i++)
    {
        cout << b[i] << " ";
    }
    return 0;
}