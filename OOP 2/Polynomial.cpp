#include <bits/stdc++.h>
using namespace std;

class Polynomial
{
private:
    int *degcoeff;
    int capacity;

public:
    Polynomial()
    {
        degcoeff = new int[5];

        capacity = 5;
        for (int i = 0; i < capacity; i++)
        {
            degcoeff[i] = 0;
        }
    }
    Polynomial(Polynomial const &p)
    {
        int *newdeg = new int[p.capacity];
        for (int i = 0; i < p.capacity; i++)
        {
            newdeg[i] = degcoeff[i];
        }
        capacity = p.capacity;

        delete[] degcoeff;
        degcoeff = newdeg;
    }

    void operator=(Polynomial const &p)
    {
        int *newdeg = new int[p.capacity];
        for (int i = 0; i < p.capacity; i++)
        {
            newdeg[i] = degcoeff[i];
        }
        capacity = p.capacity;

        delete[] degcoeff;
        degcoeff = newdeg;
    }

    void print() const
    {
        for (int i = 0; i < capacity; i++)
        {
            cout << degcoeff[i] << "x" << i << " ";
        }
        cout << endl;
    }

    Polynomial operator+(Polynomial const &p)
    {
        Polynomial pnew;
        pnew.capacity = max(capacity, p.capacity);

        pnew.degcoeff = new int[pnew.capacity];
        if (capacity < p.capacity)
        {
            int k = 0;
            for (; k < capacity; k++)
            {
                pnew.degcoeff[k] = degcoeff[k] + p.degcoeff[k];
            }
            for (; k < p.capacity; k++)
            {
                pnew.degcoeff[k] = p.degcoeff[k];
            }
        }
        else
        {
            int k = 0;
            for (; k < p.capacity; k++)
            {
                pnew.degcoeff[k] = degcoeff[k] + p.degcoeff[k];
            }
            for (; k < capacity; k++)
            {
                pnew.degcoeff[k] = p.degcoeff[k];
            }
        }

        return pnew;
    }
    Polynomial operator-(Polynomial const &p)
    {
        Polynomial pnew;
        pnew.capacity = max(capacity, p.capacity);

        pnew.degcoeff = new int[pnew.capacity];
        if (capacity < p.capacity)
        {
            int k = 0;
            for (; k < capacity; k++)
            {
                pnew.degcoeff[k] = degcoeff[k] - p.degcoeff[k];
            }
            for (; k < p.capacity; k++)
            {
                pnew.degcoeff[k] = -p.degcoeff[k];
            }
        }
        else
        {
            int k = 0;
            for (; k < p.capacity; k++)
            {
                pnew.degcoeff[k] = degcoeff[k] - p.degcoeff[k];
            }
            for (; k < capacity; k++)
            {
                pnew.degcoeff[k] = -p.degcoeff[k];
            }
        }

        return pnew;
    }
    Polynomial operator*(Polynomial const &p)
    {
        Polynomial pnew;
        pnew.capacity = capacity + p.capacity;

        pnew.degcoeff = new int[pnew.capacity];
        for (int i = 0; i < pnew.capacity; i++)
        {
            pnew.degcoeff[i] = 0;
        }
        for (int i = 0; i < capacity; i++)
        {
            for (int j = 0; j < p.capacity; j++)
            {
                pnew.degcoeff[i + j] += degcoeff[i] * p.degcoeff[j];
            }
        }

        return pnew;
    }
};