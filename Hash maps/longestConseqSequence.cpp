/*Longest consecutive Sequence
You are given with an array of integers that contain numbers in random order. Write a program to find the longest possible sequence of consecutive numbers using the numbers from given array.
You need to return the output array which contains consecutive elements. Order of elements in the output is not important.
Best solution takes O(n) time.
If two sequences are of equal length then return the sequence starting with the number whose occurrence is earlier in the array.
Input Format :
Line 1 : Integer n, Size of array
Line 2 : Array elements (separated by space)
Constraints :
0 <= n <= 10^8
Sample Input 1 :
13
2 12 9 16 10 5 3 20 25 11 1 8 6 
Sample Output 1 :
8 
9 
10 
11 
12
Sample Input 2 :
7
3 7 2 1 9 8 1
Sample Output 2 :
7
8
9
Explanation: Sequence should be of consecutive numbers. Here we have 2 sequences with same length i.e. [1, 2, 3] and [7, 8, 9], but output should be [7, 8, 9] because the starting point of [7, 8, 9] comes first in input array.
Sample Input 3 :
7
15 24 23 12 19 11 16
Sample Output 3 :
15 
16
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> lon(int *arr, int size)
{
    int *out = new int[size];
    map<int, int> m;
    map<int, bool> b;
    if (size == 0)
    {
        vector<int> v;
        v.push_back(0);
        return v;
    }
    int maxLength = 0;
    int manyElements = 0;
    int currIndex = 0;
    for (int i = 0; i < size; i++)
    {
        if (m.count(arr[i]) == 0)
        {
            m[arr[i]] = i;
        }

        b[arr[i]] = true;
    }
    for (int i = 0; i < size; i++)
    {
        int currElement = arr[i];
        int currlen = 1;
        int curcopy = currElement;
        if (b.count(currElement) && b[curcopy] == true)
        {
            while (1)
            {
                curcopy = curcopy + 1;
                if (b.count(curcopy) && b[curcopy] == true)
                {
                    currlen++;
                    b[curcopy] = false;
                }
                else
                {
                    break;
                }
            }
        }
        curcopy = currElement;
        int curstartElement = arr[i];
        while (1)
        {
            curcopy = curcopy - 1;
            if (b.count(curcopy) && b[curcopy] == true)
            {
                currlen++;
                b[curcopy] = false;
            }
            else
            {
                break;
            }
        }
        if (currlen > maxLength)
        {
            maxLength = currlen;
            manyElements = curstartElement;
            currIndex = m[curstartElement];
        }
        else if (currlen = maxLength)
        {
            maxLength = currlen;
            int rightNowIndex = m[curstartElement];
            if (rightNowIndex < currIndex)
            {
                manyElements = curstartElement;
            }
        }
        b[currElement] = false;
    }
    vector<int> v;
    while (maxLength != 0)
    {
        v.push_back(manyElements);
        manyElements++;
        maxLength--;
    }
    return v;
}

int main()
{

    return 0;
}