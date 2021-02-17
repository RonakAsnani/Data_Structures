/*
Code : Max Priority Queue
Implement the class for Max Priority Queue which includes following functions -
1. getSize -
Return the size of priority queue i.e. number of elements present in the priority queue.
2. isEmpty -
Check if priority queue is empty or not. Return true or false accordingly.
3. insert -
Given an element, insert that element in the priority queue at the correct position.
4. getMax -
Return the maximum element present in the priority queue without deleting. Return -Infinity if priority queue is empty.
5. removeMax -
Delete and return the maximum element present in the priority queue. Return -Infinity if priority queue is empty.
Note : main function is given for your reference which we are using internally to test the class.*/

#include <bits/stdc++.h>
using namespace std;

class PriorityMax
{
    vector<int> v;

public:
    PriorityMax()
    {
    }

    int getSize()
    {
        return v.size();
    }
    bool isEmpty()
    {
        return v.size() == 0;
    }

    int getMax()
    {
        return v[0];
    }
    void insert(int x)
    {
        v.push_back(x);
        int childIndex = v.size() - 1;
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (v[childIndex] > v[parentIndex])
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

    int removeMax()
    {
        int t = v[0];
        v[0] = v[v.size() - 1];
        v.pop_back();

        int parentIndex = 0;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;

        while (leftChildIndex < v.size())
        {
            int maxIndex = parentIndex;
            if (v[leftChildIndex] > v[maxIndex])
            {
                maxIndex = leftChildIndex;
            }
            if (rightChildIndex < v.size() && v[rightChildIndex] > v[maxIndex])
            {
                maxIndex = rightChildIndex;
            }
            if (maxIndex == parentIndex)
            {
                break;
            }
            int temp = v[maxIndex];
            v[maxIndex] = v[parentIndex];
            v[parentIndex] = temp;

            parentIndex = maxIndex;
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndex = 2 * parentIndex + 2;
        }
        return t;
    }
};