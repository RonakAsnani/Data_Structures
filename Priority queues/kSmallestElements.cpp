/*  
Code : K smallest Elements
You are given with an integer k and an array of integers that contain numbers in random order. Write a program to find k smallest numbers from given array. You need to save them in an array and return it.
Time complexity should be O(nlogk) and space complexity should be not more than O(k).
Order of elements in the output is not important.
Input Format :
Line 1 : Size of array (n)
Line 2 : Array elements (separated by space)
Line 3 : Integer k
Output Format :
k smallest elements
Sample Input 1 :
13
2 12 9 16 10 5 3 20 25 11 1 8 6 
4
Sample Output 1 :
5
3
2
1
*/

#include <bits/stdc++.h>
using namespace std;

int *kSmallest(int *a, int n, int k)
{
    priority_queue<int> p;
    int *out = new int[k];
    for (int i = 0; i < k; i++)
    {
        p.push(a[i]);
    }
    for (int i = k; i < n; i++)
    {
        if (p.top() > a[i])
        {
            p.pop();
            p.push(a[i]);
        }
    }
    int j = 0;
    while (!p.empty())
    {
        out[j] = p.top();
        p.pop();
        j++;
    }

    return out;
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
    int k;
    cin >> k;
    int *out = kSmallest(a, n, k);
    for (int i = 0; i < k; i++)
    {
        cout << out[i] << " ";
    }
    return 0;
}
