/*Node with maximum child sum
Given a tree, find and return the node for which sum of data of all children and the node itself is maximum. In the sum, data of node itself and data of immediate children is to be taken.
Input format :
Line 1 : Elements in level order form separated by space (as per done in class). Order is - 
Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element 
Output format :
Node with maximum sum.
Sample Input 1 :
5 3 1 2 3 1 15 2 4 5 1 6 0 0 0 0
Sample Output 1 :
1*/

#include <bits/stdc++.h>
#include <queue>
#include "TreeNode.h"
using namespace std;

TreeNode<int> *maxNode(TreeNode<int> *root)
{
    queue<TreeNode<int> *> s;
    stack<TreeNode<int> *> q;
    s.push(root);
    int m = 0;
    while (!s.empty())
    {
        TreeNode<int> *front = s.front();
        s.pop();
        int x = front->data;
        for (int i = 0; i < front->children.size(); i++)
        {
            x += front->children[i]->data;
            s.push(front->children[i]);
        }

        if (x > m)
        {
            m = x;
            q.push(front);
        }
    }
    return q.top();
}
