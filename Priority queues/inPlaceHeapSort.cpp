/*Code : In-place heap sort
Given an integer array of size n. Sort this array (in decreasing order) using heap sort.
Space complexity should be O(1).
Input Format :
Line 1 : Integer n, Array size
Line 2 : Array elements, separated by space
Output Format :
Array elements after sorting
Constraints :
1 <= n <= 10^6
Sample Input:
6 
2 6 8 5 4 3
Sample Output:
8 6 5 4 3 2*/

#include <bits/stdc++.h>
using namespace std;

void inPlaceHeapSort(int v[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int childIndex = i;
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (v[childIndex] < v[parentIndex])
            {
                int temp = v[childIndex];
                v[childIndex] = v[parentIndex];
                v[parentIndex] = temp;
            }
            else
            {
                break;
            }
            childIndex = parentIndex;
        }
    }
    int size = n;
    while (size > 1)
    {
        int t = v[0];
        v[0] = v[size - 1];
        v[size - 1] = t;

        int parentIndex = n - 1;
        int leftChild = 2 * parentIndex + 1;
        int rightChild = 2 * parentIndex + 2;

        while (leftChild < n)
        {
            int minINdex = parentIndex;
            if (v[leftChild] < v[minINdex])
            {
                minINdex = leftChild;
            }
            if (rightChild < n && v[rightChild] < v[minINdex])
            {
                minINdex = rightChild;
            }
            if (minINdex == parentIndex)
            {
                break;
            }
            int temp = v[minINdex];
            v[minINdex] = v[parentIndex];
            v[parentIndex] = temp;

            parentIndex = minINdex;
            leftChild = 2 * parentIndex + 1;
            rightChild = 2 * parentIndex + 2;
            n--;
        }
    }
}