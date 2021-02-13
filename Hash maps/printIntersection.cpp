/*Code : Print Intersection
Given two random integer arrays, print their intersection. That is, print all the elements that are present in both the given arrays.Input arrays can contain duplicate elements.Note : Order of elements are not important
Sample Input 1 :
6
2 6 8 5 4 3
4
2 3 4 7 
Sample Output 1 :
2 
4 
3
Sample Input 2 :
4
2 6 1 2
5
1 2 3 4 2
Sample Output 2 :
2 
2
1*/

#include <bits/stdc++.h>
using namespace std;

void inter(int *a, int asize, int *b, int bsize)
{
    // vector<int> *v = new vector<int>();
    unordered_map<int, int> m;
    for (int i = 0; i < asize; i++)
    {
        if (m.count(a[i]) > 0)
        {
            continue;
        }
        else
        {
            m[a[i]] = 1;
        }
    }
    for (int i = 0; i < bsize; i++)
    {
        if (m.count(b[i]) > 0)
        {
            if (m[b[i]] == 2)
            {
                continue;
            }
            else
            {
                m[b[i]]++;
                cout << b[i] << endl;
            }
        }
        else
        {
            continue;
        }
    }
}
