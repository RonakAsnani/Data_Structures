#include <bits/stdc++.h>
using namespace std;

vector<int> romove(int *a, int size)
{
    vector<int> output;
    unordered_map<int, bool> seen;
    for (int i = 0; i < size; i++)
    {
        if (seen.count(a[i]) > 0)
        {
            continue;
        }
        seen[a[i]] = true;
        output.push_back(a[i]);
    }
    return output;
}

int main()
{
    int a[] = {1, 2, 3, 4, 3, 4, 2, 1, 5, 6, 7, 1, 1, 4};
    vector<int> out = romove(a, 11);
    for (int i = 0; i < out.size(); i++)
    {
        cout << out.at(i) << " " << endl;
    }
}