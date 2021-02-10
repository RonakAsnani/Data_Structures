/*
Structurally identical
Given two Generic trees, return true if they are structurally identical i.e. they are made of nodes with the same values arranged in the same way.
Input format :
Line 1 : Tree 1 elements in level order form separated by space (as per done in class). Order is - 
Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element 
Line 2 : Tree 2 elements in level order form separated by space (as per done in class). Order is - 
Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element 
Output format :
true or false
Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0 
10 3 20 30 40 2 40 50 0 0 0 0
Sample Output 1 :
true
Sample Input 2 :
10 3 20 30 40 2 40 50 0 0 0 0 
10 3 2 30 40 2 40 50 0 0 0 0
Sample Output 2:
false*/

#include <bits/stdc++.h>
#include <queue>
#include "TreeNode.h"
using namespace std;

bool identical(TreeNode<int> *a, TreeNode<int> *b)
{
    stack<int> s1;
    stack<int> s2;
    queue<TreeNode<int> *> q1;
    queue<TreeNode<int> *> q2;

    s1.push(a->data);
    s2.push(b->data);
    q1.push(a);
    q2.push(b);

    while (!q1.empty())
    {
        TreeNode<int> *front = q1.front();
        q1.pop();
        s1.push(front->children.size());
        for (int i = 0; i < front->children.size(); i++)
        {
            q1.push(front->children[i]);
            s1.push(front->children[i]->data);
        }
    }
    while (!q2.empty())
    {
        TreeNode<int> *front = q2.front();
        q2.pop();
        s2.push(front->children.size());
        for (int i = 0; i < front->children.size(); i++)
        {
            q2.push(front->children[i]);
            s2.push(front->children[i]->data);
        }
    }
    bool ans = true;
    if (s1.size() == s2.size())
    {
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1.top() == s2.top())
            {
                s1.pop();
                s2.pop();
            }
            else
            {
                ans = false;
            }
        }
    }
    else
    {
        ans = false;
    }
    return ans;
}