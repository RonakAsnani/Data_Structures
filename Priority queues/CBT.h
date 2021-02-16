#include <bits/stdc++.h>
using namespace std;

class CBT
{
private:
    int *a;
    int size;
    int nextIndex;

public:
    CBT()
    {
        nextIndex = 0;
        size = 5;
        a = new int[size];
    }

    void insert(int x)
    {
        if (nextIndex == size)
        {
            int *b = new int[2 * size];
            for (int i = 0; i < size; i++)
            {
                b[i] = a[i];
            }
            size *= 2;
            int *temp = a;
            a = b;
            delete a;
        }
        else
        {
            a[nextIndex] = x;
            nextIndex++;
        }
    }
    int remove()
    {
        int ans = a[nextIndex];
        nextIndex--;
        return ans;
    }
    pair<int, int> getChildren(int x)
    {
        int index;
        for (int i = 0; i < size; i++)
        {
            if (a[i] == x)
            {
                index = i;
                break;
            }
        }
        pair<int, int> p;
        p.first = a[2 * index - 1];
        p.second = a[2 * index + 1];
        return p;
    }
    int getParent(int x)
    {
        int index;
        for (int i = 0; i < size; i++)
        {
            if (a[i] == x)
            {
                index = i;
                break;
            }
        }
        index = (index - 1) / 2;
        return a[index];
    }
};