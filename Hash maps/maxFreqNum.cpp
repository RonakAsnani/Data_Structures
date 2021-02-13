/*Code : Maximum Frequency Number
You are given an array of integers that contain numbers in random order. Write a program to find and return the number which occurs the maximum times in the given input.
If two or more elements contend for the maximum frequency, return the element which occurs in the array first.
Sample Input 1 :
13
2 12 2 11 12 2 1 2 2 11 12 2 6 
Sample Output 1 :
2
Sample Input 2 :
3
1 4 5
Sample Output 2 :
1*/

#include <bits/stdc++.h>
using namespace std;

int max(int *a, int size)
{
    unordered_map<int, int> maxi;
    for (int i = 0; i < size; i++)
    {
        if (maxi.count(a[i]) > 0)
        {
            maxi[a[i]]++;
        }
        else
        {
            maxi[a[i]] = 1;
        }
    }
    int m = INT_MIN;
    int ans = 0;
    for (int i = 0; i < maxi.size(); i++)
    {
        if (maxi[a[i]] > m)
        {
            m = maxi[a[i]];
            ans = a[i];
        }
    }
    return ans;
}
