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
    int removeMin()
    {
        int t = v.at(0);
        v.at(0) = v.at(v.size() - 1);
        v.at(v.size() - 1) = t;
        v.pop_back();

        int parent = 0;
        int child1 = 2 * parent + 1;
        int child2 = 2 * parent + 2;
        while (parent < v.size())
        {
            if (v.at(parent) < v.at(child1) && v.at(parent) < v.at(child2))
            {
                return t;
            }
            else if (v.at(parent) > v.at(child1) && v.at(parent) > v.at(child2))
            {
                if (v.at(child1) < v.at(child2))
                {
                    int temp = v.at(parent);
                    v.at(parent) = v.at(child1);
                    v.at(child1) = temp;
                    parent = child1;
                }
                else
                {
                    int temp = v.at(parent);
                    v.at(parent) = v.at(child2);
                    v.at(child2) = temp;
                    parent = child2;
                }
            }
        }
    }
};

int main()
{

    return 0;
}