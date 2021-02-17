#include <bits/stdc++.h>
using namespace std;

class MinHeap
{
    vector<int> v;

public:
    MinHeap()
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
        else
        {
            return v.at(0);
        }
    }
    void insert(int x)
    {
        v.push_back(x);
        int childIndex = v.size() - 1;
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (v.at(childIndex) < v.at(parentIndex))
            {
                int temp = v.at(childIndex);
                v.at(childIndex) = v.at(parentIndex);
                v.at(parentIndex) = temp;
            }
            else
            {
                break;
            }
            childIndex = parentIndex;
        }
    }
    // check
    int removeMin()
    {
        if (isEmpty())
        {
            return 0;
        }
        int t = v.at(0);
        v.at(0) = v.at(v.size() - 1);
        v.pop_back();

        int parent = 0;
        int child1 = 2 * parent + 1;
        int child2 = 2 * parent + 2;
        while (child1 < v.size())
        {
            int minIndex = parent;
            if (v[minIndex] > v[child1])
            {
                minIndex = child1;
            }
            if (child2 < v.size() && v[child2] < v[minIndex])
            {
                minIndex = child2;
            }
            if (minIndex == parent)
            {
                break;
            }
            int temp = v[minIndex];
            v[minIndex] = v[parent];
            v[parent] = temp;

            parent = minIndex;
            child1 = 2 * parent + 1;
            child2 = 2 * parent + 2;
        }
    }
};

int main()
{

    return 0;
}