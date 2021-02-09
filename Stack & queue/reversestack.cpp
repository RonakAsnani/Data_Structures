#include <bits/stdc++.h>
using namespace std;

void reverseStack(stack<int> s1, stack<int> s2)
{
    if (s1.size() <= 1)
    {
        return;
    }
    int x = s1.top();
    s1.pop();
    reverseStack(s1, s2);
    while (!s1.empty())
    {
        int z = s1.top();
        s1.pop();
        s2.push(z);
    }
    s1.push(x);
    while (!s2.empty())
    {
        int d = s2.top();
        s2.pop();
        s1.push(d);
    }
}

int main()
{
    int size;
    cin >> size;
    stack<int> s1;
    for (int i = 0; i < size; i++)
    {
        int a;
        cin >> a;
        s1.push(a);
    }
    stack<int> s2;

    stack<int> w;
    reverseStack(s1, s2);
    for (int i = 0; i < size; i++)
    {
        cout << s1.top() << endl;
        s1.pop();
    }
    return 0;
}