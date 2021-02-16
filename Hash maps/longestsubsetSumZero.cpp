/*Longest subset zero sum
Given an array consisting of positive and negative integers, find the length of the longest subarray whose sum is zero.
NOTE: You have to return the length of longest subarray .
Input Format :
Line 1 : Contains an integer N i.e. size of array

Line 2 : Contains N elements of the array, separated by spaces
Output Format
 Line 1 : Length of longest subarray 
Constraints:
0 <= N <= 10^8
Sample Input :
10 
 95 -97 -387 -435 -5 -70 897 127 23 284
Sample Output :
5*/

#include <bits/stdc++.h>
using namespace std;

int length(int *a, int n)
{
    unordered_map<int, int> m;
    for (int i = 1; i < n; i++)
    {
        m[a[i]] += a[i - 1];
    }
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            if (x < i + 1)
            {
                x = i + 1;
            }
        }
        else if (m.count(a[i]) > 0)
        {
            if (x < i - m[a[i]])
            {
                x = i - m[a[i]];
            }
        }
        else
        {
            m[a[i]] = i;
        }
    }
    return 0;
}

int main()
{

    return 0;
}