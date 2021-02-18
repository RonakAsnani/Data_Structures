/*
Merge K sorted arrays
Given k different arrays, which are sorted individually (in ascending order). You need to merge all the given arrays such that output array should be sorted (in ascending order).
Hint : Use Heaps.
Input Format :
Line 1 : Integer K
Line 2 : Arrays 1 size (n1)
Line 3 : Array 1 elements (separated by space)
Line 4 : Array 2 size (n2)
and so on for next arrays
Sample Input 1 :
4
3
1 5 9
2
45 90
5
2 6 78 100 234
1
0
Sample Output 1 :
0 1 2 5 6 9 45 78 90 100 234*/

#include <bits/stdc++.h>
using namespace std;

vector<int> sort(vector<vector<int> *> input)
{
    int size = input.size() - 1;

    // int* a = input[size];
    vector<int> out;
    priority_queue<int> pq;
    for (int i = 0; i < size; i++)
    {
        vector<int> *q = input[i];
        for (int j = 0; j < q->size(); j++)
        {
            pq.push(q->at(j));
        }
    }
    while (!pq.empty())
    {
        out.push_back(pq.top());
        pq.pop();
    }
}