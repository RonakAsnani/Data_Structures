#include <bits/stdc++.h>
using namespace std;

class PriorityQueue
{
    vector<int> v;

public:
    PriorityQueue()
    {
    }

    bool isEmpty()
    {
        return v.size() == 0;
    }
    int getSize()
    {
        return v.size();
    }
    int getMin()
    {
        if (isEmpty())
        {
            return 0;
        }
        return v.at(0);
    }
    void insert(int x)
    {
        v.push_back(x);
        int childIndex = v.size() - 1;

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

    int removeMin()
    {
        if (isEmpty())
        {
            return 0;
        }
        int t = v[0];
        v[0] = v[v.size() - 1];
        v.pop_back();

        int parentIndex = 0;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;

        while (leftChildIndex < v.size())
        {
            int minIndex = parentIndex;
            if (v[leftChildIndex] < v[minIndex])
            {
                minIndex = leftChildIndex;
            }
            if (rightChildIndex < v.size() && v[rightChildIndex] < v[minIndex])
            {
                minIndex = rightChildIndex;
            }
            if (minIndex = parentIndex)
            {
                break;
            }
            int temp = v[parentIndex];
            v[parentIndex] = v[minIndex];
            v[minIndex] = temp;

            parentIndex = minIndex;
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndex = 2 * parentIndex + 2;
        }
        return t;
    }
};